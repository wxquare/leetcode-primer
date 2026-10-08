# 工程示例

本目录收录后端面试中适合通过代码练习的并发、资源管理、设计模式和限流示例。算法与数据结构模板位于[算法实现目录](../../algorithm-interview/implementations/README.md)，这里仅通过链接引用，避免重复维护。

| 主题 | 示例 |
| --- | --- |
| C++ 资源与字符串 | [string_raii.cc](src/string_raii.cc)、[string_raii_copy_move.cc](src/string_raii_copy_move.cc)、[c_string_operations.cc](src/c_string_operations.cc)、[integer_conversion.cc](src/integer_conversion.cc) |
| 设计模式 | [factory_pattern.cc](src/factory_pattern.cc)、[visitor_pattern.cc](src/visitor_pattern.cc)、[singleton_pattern.cc](src/singleton_pattern.cc) |
| C++ 并发 | [bounded_producer_consumer.cc](src/bounded_producer_consumer.cc)、[read_write_locker.cc](src/read_write_locker.cc) |
| Go 并发 | [concurrency_dining_philosophers.go](src/concurrency_dining_philosophers.go)、[concurrency_h2o.go](src/concurrency_h2o.go)、[concurrency_producer_consumer.go](src/concurrency_producer_consumer.go)、[concurrency_producer_consumer_sum.go](src/concurrency_producer_consumer_sum.go)、[concurrency_turn_based_print.go](src/concurrency_turn_based_print.go)、[concurrency_turn_based_string.go](src/concurrency_turn_based_string.go)、[concurrency_zero_even_odd.go](src/concurrency_zero_even_odd.go) |
| Redis 限流 | [lua_token_rate_limit.lua](src/lua_token_rate_limit.lua)、[lua_token_limiter.py](src/lua_token_limiter.py) |

源码按独立示例保存，可依据文件中的入口和注释单独编译或运行。
