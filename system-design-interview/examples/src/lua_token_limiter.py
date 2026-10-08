import redis
import time

class RateLimiter:
    def __init__(self, redis_host, redis_port, capacity, rate):
        self.redis = redis.Redis(host=redis_host, port=redis_port)
        self.capacity = capacity
        self.rate = rate

    def limit(self, key, amount):
        script = """
            local key = KEYS[1]
            local capacity = tonumber(ARGV[1])
            local rate = tonumber(ARGV[2])
            local amount = tonumber(ARGV[3])
            local frozen_key = string.format("%s_frozen",key)

            if redis.call('GET',frozen_key) then
                return 0
            end

            local time = redis.call('time')
            local time_micro = tonumber(time[1]) * 1000000 + tonumber(time[2])

            local tokens = tonumber(redis.call('HGET',key,'tokens') or capacity)
            local last_updated = tonumber(redis.call('HGET',key,'last_updated') or time_micro)

            local new_add = math.floor((time_micro - last_updated) * rate / 1000000)
            local new_token = math.min(capacity,tokens + new_add)

            if new_token >= amount then
                new_token = new_token - amount
                redis.call('HSET',key,'tokens',new_token,'last_updated',time_micro)
                return 1
            else
                redis.call('SETEX',frozen_key,10,time_micro)
                return 0
            end
        """
        lua_script = self.redis.register_script(script)
        result = lua_script(keys=[key], args=[self.capacity, self.rate, amount])
        return bool(result)

# 示例用法
redis_host = '127.0.0.1'
redis_port = 6379
capacity = 100  # 令牌桶容量
rate = 10  # 令牌发放速率

limiter = RateLimiter(redis_host, redis_port, capacity, rate)

key = 'my_key'
amount = 5

for i in range(10000):
    time.sleep(1/1000.0*10)
    if limiter.limit(key, amount):
        print("pass",i)
    else:
        print("limit",i)
        time.sleep(1)
