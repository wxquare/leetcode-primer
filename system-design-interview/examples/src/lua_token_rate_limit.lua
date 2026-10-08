local key = KEYS[1]
local capacity = tonumber(ARGV[1])
local rate = tonumber(ARGV[2])
local amount = tonumber(ARGV[3])
local frozen_key = string.format("%s_frozen",key)

if redis.call('GET',frozen_key) then
    return 0

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