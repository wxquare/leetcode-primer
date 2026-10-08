# 通用与非电商系统设计面试题：100 题

覆盖系统设计基础、数据与中间件、可靠性和安全，以及酒店、出行、即时通讯、内容平台、协同编辑和 IoT 等非电商系统。

## 分类地图与记忆主线

通用能力记忆：明确目标与约束 → 估算容量 → 划定数据边界 → 设计主链路 → 处理故障 → 复盘演进。

| 主题 | 题号范围 | 记忆线索 |
| --- | ---: | --- |
| 系统设计基础与架构演进 | 1–10 | 目标 → 范围 → 约束 → 方案取舍 → 演进验证 |
| 容量、性能与流量治理 | 11–17 | 基线 → 峰值 → 热点 → 冗余与降级 |
| 非电商业务系统 | 18–47 | 用户与场景 → 核心流程 → 权威状态 → 异常恢复 |
| 数据建模、一致性与数据处理 | 48–67 | 事实归属 → 一致性边界 → 事务 → 修复对账 |
| 中间件、存储与异步处理 | 68–87 | 同步或异步 → 投递可靠 → 消费幂等 → 重放恢复 |
| 可靠性、安全与可观测性 | 88–100 | 保护 → 观测 → 隔离 → 恢复 |

## 高频题速记

| 主题 | 核心方案 |
| --- | --- |
| 分布式限流 | 固定/滑动窗口、漏桶、令牌桶、Redis Lua、自适应限流 |
| 热点 Key 治理 | 探测、本地缓存、Key 分散、隔离线程池 |
| 熔断、降级、限流边界 | 限流防激增、熔断防雪崩、降级保核心、兜底保体验 |
| AI Agent 高并发架构 | 全异步、SSE、语义缓存、模型路由、工具限流 |
| 短链接服务 | 发号器 + Base62 + 缓存重定向 + 布隆过滤器 |
| Feed 流 | 推/拉/推拉结合、大 V 问题、缓存时间线、分页 |
| 评论系统 | 楼中楼、分页、热点评论、缓存与 DB 一致性 |
| 消息通知系统 | 事件订阅、渠道适配、模板、限流、重试与幂等 |
| 分布式事务 | 2PC/TCC/Saga/Outbox；区分同步承诺与异步补偿 |
| Redis / MySQL 双写一致性 | Cache Aside、延迟双删、Binlog 订阅、对账补偿 |
| 分布式锁 | Redis SET NX EX + Lua + Watchdog；ZooKeeper/Etcd 兜底 |
| 接口幂等性 | 唯一索引、Token、幂等表、状态机前置校验 |
| 数据迁移、双写切换与最终一致性 | 双写、回放、校验、灰度切流、回滚窗口 |
| 40 亿数据去重 | Bitmap 512MB、Bloom Filter、HyperLogLog |
| 实时排行榜 | Redis ZSet、分桶归并、快照分页 |
| 海量数据排序 | 分块快排 + 多路归并 + 分布式排序 |
| 10 亿用户在线状态 | Bitmap + Redis BITCOUNT + 分片 |
| 分布式 ID | Snowflake、数据库号段、Redis INCR、时钟回拨处理 |
| MySQL 分库分表 | 水平/垂直拆分、分片键、分布式事务与迁移 |
| Redis 核心问题 | 数据结构、持久化、集群、缓存雪崩/穿透/击穿、锁 |
| 消息队列选型 | Kafka/RocketMQ/RabbitMQ；顺序、可靠性、积压、幂等 |
| Elasticsearch 架构 | 倒排索引、分片副本、Mapping、深分页、脑裂 |
| ClickHouse / OLAP 选型 | 列存、MergeTree、实时数仓、离在线链路 |
| 线程池设计 | 核心/最大线程、队列、拒绝策略、监控与告警 |
| 异步并行优化 | CompletableFuture、批量、并行度、线程池隔离 |
| 认证鉴权 Session/JWT/OAuth2/SSO | 会话存储、JWT 过期/吊销、SSO、权限模型 |
| 常见 Web 攻防 | SQLi/XSS/CSRF/SSRF、限流、WAF、安全响应 |
| HTTPS 握手与加密 | TLS 1.3、证书链、密钥交换、中间人防护 |
| 日志、指标、链路追踪三大支柱 | 结构化日志、Metrics、TraceID、SLO |
| 接口突然变慢排查 | 监控 → 日志 → 链路 → SQL/GC/依赖 → 回滚/扩容 |
| 线上故障排查与复盘 | 止血、定位、修复、复盘、改进项闭环 |
| SLI / SLO / 错误预算 | 用户可感知指标、目标、预算、告警与研发节奏 |
| 故障演练、混沌工程与降级预案 | 注入故障、预案、恢复演练、复盘 |
| 分布式任务调度 | 分片、重试、幂等、Leader 选举、超时治理 |
| 对象存储 / 文件上传下载 | 直传/分片/断点、OSS、预签名、回调校验 |
| API 网关、注册中心、配置中心 | 路由、鉴权、限流、动态配置、服务发现 |
| 单体到微服务 / 中台化拆分 | 业务边界、领域模型、数据拆分、演进节奏 |

## 通用面试速答

### 瓶颈定位

先判断数据库、缓存、消息队列、线程池或外部依赖，再用指标、日志和调用链缩小范围；止血与根因修复分开推进。

### 流量突增

按限流、扩容、缓存、异步削峰、隔离降级的顺序保护核心路径，并说明触发条件与恢复阈值。

### 故障处理

先控制影响和保护数据，再定位根因、恢复服务、核对数据，最后复盘责任与改进项。

### 方案取舍

回答每项设计时同时说明收益、复杂度、成本和适用边界，避免只列组件名。


## 练习指南

每道题从目标、约束、权威状态、主链路、失败处理和演进取舍展开。先明确题目要保护的业务事实，再选择组件。

#### 候选人训练

练习核心案例时，按下面顺序展开：

1. 确认用户目标、成功指标、非目标和不可接受的业务损失。
2. 写出会改变设计的规模假设、峰值集中度和外部依赖。
3. 标明关键事实由谁权威保存，以及状态如何迁移。
4. 描述正常链路、同步确认点和可异步的派生副作用。
5. 处理题目中的故障注入：超时、重复、乱序、积压或依赖失效。
6. 说明当前方案为何成立，什么阈值会触发下一阶段演进。

变体练习先复述基线方案中的一个关键决定，再只修改受新约束影响的部分。快问快答则以“结论、理由、边界”收束，避免把单点知识题回答成架构漫谈。

#### 面试官评估

面试官不应根据候选人是否提到了缓存、消息队列或分库分表评分。应观察候选人是否：

| 观察点 | 可接受表现 | 深入表现 |
| --- | --- | --- |
| 问题定义 | 问出影响方案的约束 | 能排序冲突目标并说明影响 |
| 关键状态 | 指出权威数据与状态前置条件 | 给出审计、幂等和恢复责任 |
| 主链路 | 区分同步承诺与异步副作用 | 解释用户可见结果与未知结果 |
| 故障处理 | 回应题目中的具体失败 | 给出监测、重试、对账和人工边界 |
| 取舍 | 说明选择的成本 | 说明何时应推翻当前选择 |

追问一次只改变一个条件，并要求候选人明确哪些结论仍成立。不要在候选人尚未给出基线方案前连续追加多个灾难场景。

#### 复盘记录

每次训练只记录一个可验证改进动作，例如“下次先定义支付超时后的未知状态”，或“下次说明索引版本落后时的重建入口”。下次练习选择同一核心案例的约束变体，验证这个动作是否真的改变了决策。

可从开篇分类地图选择训练入口，再根据题目中的约束变化检查方案是否仍然成立。

#### 答题方法与复盘

#### 系统设计面试在考什么

系统设计题考察的不是背诵某个组件，而是能否在信息不完整时定义问题、组织方案并说明取舍。重点包括：

| 维度 | 要回答的问题 |
| --- | --- |
| 问题理解 | 目标、范围、非目标和不可接受的业务损失是什么？ |
| 结构化思考 | 入口、核心链路、权威状态、读模型和治理机制如何协作？ |
| 工程判断 | 一致性、可用性、成本和复杂度为何这样取舍？ |
| 风险意识 | 热点、超时、重复、积压、数据修复和降级如何闭环？ |
| 沟通表达 | 结论是否有顺序，且每个选择都能说清依据与边界？ |

#### 回答与白板的展开顺序

先报结构，再按主链路展开；第一张图只画边界、同步关系、权威数据和主要依赖，局部细节只在被追问时补充。

1. 确认业务目标、成功指标、非目标和风险底线。
2. 给出会改变设计的规模、峰值、读写比例和外部依赖假设。
3. 画入口、服务边界、权威存储、缓存、消息和下游的主链路。
4. 区分同步承诺与异步副作用，说明状态前置条件和幂等边界。
5. 处理超时、重试、乱序、积压和依赖失效，给出监测与恢复责任。
6. 收束当前瓶颈、降级优先级、验证指标和规模扩大后的演进触发条件。

白板不需要一开始画完所有服务。它应让读者看出每条关键连线的方向、同步方式、失败去向，以及业务事实保存在哪里。

#### 容量估算口径

容量估算以数量级正确和能够改变设计为目标。先从业务行为推导入口、读写、重试、异步和外部依赖压力，再把结论落到缓存、队列、数据库、网络与隔离预算。

```text
峰值下单 QPS = 高峰活跃用户 x 下单转化率 / 峰值时间窗口
真实写压力 = 下单 + 库存校验 + 幂等校验 + 支付回调 + 重试
异步压力 = 业务事件 + 消费重试 + 索引同步 + 对账与补偿
```

大促、秒杀等场景不能按全天均匀流量估算。除入口 QPS 外，必须估算热点商品、消息积压、存储增长、带宽、第三方限额以及恢复期间的补偿流量。

#### 存储、中间件与可靠性的答题边界

- **MySQL：** 用于需要事务、约束、审计和恢复的订单、支付、库存账本等权威状态；缓存和搜索不能替代其状态责任。
- **Redis：** 用于热点缓存、原子令牌、限流和短期状态；它提升吞吐和延迟表现，但不单独证明交易正确性。
- **消息队列：** 用于削峰、异步事件传播、重试和解耦；仍需 Outbox、业务幂等、积压治理和补偿闭环。
- **Elasticsearch：** 用于全文检索、多字段筛选、排序和聚合；它是派生读模型，需允许索引延迟并支持重建和降级。

谈可靠性必须落到具体对象：超时限制等待，重试应对瞬时失败，幂等防止重复副作用；熔断保护调用方，降级保护核心业务。交易结果未知时，不能把调用超时直接解释为失败或成功，应通过状态查询、对账和人工边界收敛。

#### 高频题型与复盘

秒杀、库存和红包的核心矛盾是高并发下的资源正确性；短链接、ID 和评论的核心矛盾是数据模型与读写路径；Feed、排行榜和监控的核心矛盾是扇出、实时性和成本；支付、订单和跨域事务的核心矛盾是状态一致性与恢复；搜索和推荐的核心矛盾是查询能力与派生数据的时效。

复盘时检查三层问题：结构上是否先讲约束、主链路和权威状态；内容上是否每个结论都有依据、边界和代价；表达上是否能用简短结论收束而不堆砌术语。下一次练习只选择一个能验证的改进动作。

## 练习路线

先练需求澄清与容量估算，再选一个非电商业务系统完成主链路设计，最后用故障注入检查一致性、降级和恢复。每轮只记录一个可验证的改进点。

## 1. 系统设计基础与架构演进

#### 1. 单体到服务化的演进决策

**题型：** 核心案例，45 分钟
**目标：** 针对快速增长的平台，决定哪些问题应先通过模块化、数据边界或平台能力解决，哪些才值得拆为独立服务。

##### 不可协商约束

- 不得把团队规模、日订单量或“使用微服务”当成拆分理由本身。
- 每次拆分必须说明数据所有权、契约、迁移路径、回滚方式和新增运营成本。
- 架构演进应由变化频率、故障隔离、扩缩容需求和组织协作证据驱动。

##### 关键决策

1. 如何选择第一个被隔离的能力，并证明其收益大于迁移成本。
2. 如何避免双写、共享数据库和跨服务同步调用成为长期耦合。
3. 配置、追踪、版本兼容、技术债和可观测性如何随服务数量演进。

##### 故障注入

拆出的库存服务与旧单体并行写入期间出现版本偏差。说明切流、对账、停写与回滚策略。


#### 2. 系统设计面试与算法面试的区别是什么？

##### 题干与约束
说明系统设计面试与算法面试考察的差异，以及为什么系统设计题应先澄清问题。
##### 答案骨架
算法题更强调在确定条件下构造正确、高效的求解；系统设计题要求在信息不完整时定义问题、选取边界并解释取舍。先澄清可避免为错误目标堆组件，随后才能讨论容量、数据与可靠性。
##### 递进追问
业务方只说“用户很多且必须稳定”时，下一句如何追问？
##### 常见失分点
把系统设计说成算法题的放大版；直接罗列中间件；遗漏非目标。


#### 3. 什么是系统设计？系统设计面试到底在考什么？

追问：你会如何区分“会用组件”和“有设计能力”？


#### 4. 为什么架构师不能只会画图或列接口？

追问：一份真正可评审的 TD 至少要回答哪些关键问题？


#### 5. 技术方案里的关键设计决策应该怎么写？

追问：如果你列了 A/B 方案，怎么证明你选的那个更合理？


#### 6. 如果让你在 5 分钟内回答一道系统设计题，你会按什么顺序组织表达？

追问：这个顺序和你写真实 TD 时有什么共通点？


#### 7. 为什么很多 TD 会在 rollout 和 rollback 上被打回？

追问：你会如何把灰度、观测、回滚写成可执行方案？


#### 8. 高频系统设计题的底层共性是什么？

##### 题干与约束
秒杀、库存、支付、短链接和 Feed 流题面不同，如何归纳可迁移的设计模式？
##### 答案骨架
高频题通常归结为：热点与吞吐，使用削峰、排队、预热和隔离；业务事实正确性，使用权威状态、条件更新、状态机和对账；跨系统副作用，使用可靠事件、幂等、补偿与观测；复杂读，使用读模型、缓存和可接受的最终一致。题面变化时先识别主矛盾，再选择模式。
##### 递进追问
若只能优先解决一个问题，如何从资损、用户体验和系统吞吐中排序？
##### 常见失分点
只按组件分类；把所有题归为缓存或消息队列；没有权威状态和失败恢复。


#### 9. 系统设计面试后如何复盘并改进？

##### 题干与约束
一次面试后发现自己“懂很多但讲不清”，如何建立下一轮训练计划？
##### 答案骨架
结构层检查是否先讲目标、规模、主链路、状态、失败和演进；内容层检查结论是否有依据、是否遗漏权威状态与补偿；表达层检查是否先报框架、是否术语堆叠。每个失分点转成可验证动作，下一轮在改变约束后重答并比较改进。
##### 递进追问
如果每次都遗漏异常处理，下一次白板上应加入什么固定检查点？
##### 常见失分点
只看答案对错；只背更多题；没有记录假设和被追问的边界。


#### 10. 为什么说可扩展性会带来复杂度？

追问：从单体走向微服务后，通常新增了哪些治理问题？


## 2. 容量、性能与流量治理

#### 11. 如何把容量估算转化为设计依据？

##### 题干与约束
说明如何估算峰值 QPS、并发、数据量、带宽和存储增长，并把结果用于设计。
##### 答案骨架
先声明活跃用户、每人操作次数和峰值集中度；再计算核心读写 QPS，并加上重试、回调和异步消费。读高时设计缓存与读模型，写高时设计削峰和分片，热点集中时预热、隔离和限流，数据增长影响索引、归档与容量余量。
##### 递进追问
若用户流量不变但活动压缩到一分钟，哪些估算必须重做？
##### 常见失分点
只报一个 QPS；忽略重试和回调；估算后没有落到架构选择。


#### 12. 100 万酒店 10 小时如何估算吞吐？

##### 题干与约束

100 万酒店 10 小时如何估算吞吐？

##### 答案骨架


参考回答：100 万 / 10 小时约等于 27.8 个酒店/秒。如果每页 100 个酒店，大约需要 10000 页，10 小时内只需要 0.28 页/秒。但如果要逐个拉详情，就是 27.8 QPS，还要受供应商限流、超时、重试和数据处理速度约束。

##### 递进追问

- 哪些步骤必须同步确认，哪些步骤可以通过事件最终一致？
- 在重试、并发和下游不可用时，如何保证状态可恢复、可追踪？
- 规模扩大十倍后，热点、容量、隔离和降级策略如何变化？

##### 常见失分点

- 混淆领域事实、派生读模型和流程状态。
- 只描述成功路径，遗漏幂等、对账、补偿或人工处理入口。
- 把缓存、消息队列或搜索索引错误地当作交易权威来源。


#### 13. 为什么系统设计里一定要先做容量估算？

追问：如果没有精确数据，你会如何给出合理区间？


#### 14. 高并发系统为什么不能只靠加机器解决？

追问：哪些瓶颈是水平扩展也解决不了的？


#### 15. 负载均衡和缓存分别解决什么问题？

追问：它们引入了哪些新的故障模式？


#### 16. 分布式限流

##### 题干与约束
设计面向多实例服务的分布式限流能力。

##### 答案骨架
**算法对比**：

| 算法 | 优点 | 缺点 |
|------|------|------|
| **固定窗口计数器** | 实现简单 | 临界突发：窗口交界处可能 2 倍流量 |
| **滑动窗口** | 解决临界突发 | 内存开销大（需存每个请求时间戳） |
| **漏桶** | 平滑输出 | 无法应对合理突发 |
| **令牌桶** | 允许突发 | 实现稍复杂 |

**分布式实现**：Redis + Lua（ZSet 滑动窗口 / Token Bucket）。

**动态限流**：基于 CPU、RT、错误率自适应调整阈值（Sentinel / Hystrix）。

---


#### 17. 热点 Key 治理

##### 题干与约束
设计热点 Key 的发现、分散和隔离方案。

##### 答案骨架
**场景**：秒杀商品、热搜词、突发事件导致单个 Key 流量爆炸。

**方案**：
1. **探测**：实时统计 QPS，自动识别热点 Key。
2. **本地缓存**：热点 Key 复制到 JVM 内存（Caffeine），直接拦截。
3. **分散压力**：Key 后缀加随机值（`key_1 ~ key_N`），分散到多个 Redis 分片。
4. **隔离**：热点请求走独立线程池 + 独立缓存节点，不影响普通流量。

---


## 3. 非电商业务系统

#### 18. 用户画像系统的设计

##### 题干与约束

为了实现个性化推荐，需要构建用户画像（年龄、性别、消费能力、兴趣偏好）。如何设计用户画像系统？

##### 答案骨架


**问题描述**：
为了实现个性化推荐，需要构建用户画像（年龄、性别、消费能力、兴趣偏好）。如何设计用户画像系统？

**答案**：

**推荐方案**：实时+离线双层架构

```go
package userprofile

import (
	"context"
	"time"
)

// UserProfile 用户画像
type UserProfile struct {
	UserID int64

	// 基础信息
	Age    int
	Gender string
	City   string

	// 消费画像
	AvgOrderAmount    decimal.Decimal  // 客单价
	TotalOrderCount   int              // 订单数
	ConsumptionLevel  string           // 消费能力：高/中/低

	// 兴趣画像
	FavoriteCategories []int64         // 偏好类目
	FavoriteBrands     []string        // 偏好品牌
	PriceRange         PriceRange      // 价格区间

	// 行为特征
	ActiveTime         []int           // 活跃时段
	ShoppingFrequency  string          // 购物频次
	LastPurchaseTime   time.Time

	UpdatedAt time.Time
}

// UserProfileService 用户画像服务
type UserProfileService struct {
	repo        UserProfileRepository
	rdb         *redis.Client
	kafkaWriter *kafka.Writer
}

// GetProfile 获取用户画像
func (s *UserProfileService) GetProfile(ctx context.Context,
	userID int64) (*UserProfile, error) {

	// 从缓存读取
	cacheKey := fmt.Sprintf("user:profile:%d", userID)
	profileJSON, err := s.rdb.Get(ctx, cacheKey).Result()
	if err == nil {
		profile := &UserProfile{}
		json.Unmarshal([]byte(profileJSON), profile)
		return profile, nil
	}

	// 从数据库读取
	profile, err := s.repo.FindByUserID(ctx, userID)
	if err != nil {
		return nil, err
	}

	// 缓存
	profileJSON, _ = json.Marshal(profile)
	s.rdb.SetEX(ctx, cacheKey, profileJSON, 6*time.Hour)

	return profile, nil
}

// UpdateProfileRealtime 实时更新画像
func (s *UserProfileService) UpdateProfileRealtime(ctx context.Context,
	event *UserBehaviorEvent) error {

	// 将行为事件写入Kafka
	return s.kafkaWriter.WriteMessages(ctx, kafka.Message{
		Key:   []byte(fmt.Sprintf("%d", event.UserID)),
		Value: s.serializeEvent(event),
	})
}

// Flink实时计算（伪代码）
/*
用户行为流 → Flink → 实时画像

Flink Job:
1. 消费Kafka用户行为流
2. 计算实时指标（浏览、加购、下单）
3. 更新Redis画像缓存
4. 每小时写入HBase
*/

// 离线计算（每日凌晨执行）
func (s *UserProfileService) BatchUpdateProfiles() error {
	ctx := context.Background()
	yesterday := time.Now().AddDate(0, 0, -1)

	// 1. 查询昨天的用户行为数据
	behaviors, _ := s.behaviorRepo.FindByDate(ctx, yesterday)

	// 2. 聚合计算
	profileUpdates := s.aggregateBehaviors(behaviors)

	// 3. 批量更新画像
	for _, update := range profileUpdates {
		s.repo.Update(ctx, update)

		// 清除缓存
		cacheKey := fmt.Sprintf("user:profile:%d", update.UserID)
		s.rdb.Del(ctx, cacheKey)
	}

	return nil
}

// 消费能力分层
func (s *UserProfileService) calculateConsumptionLevel(
	avgOrderAmount decimal.Decimal, totalOrderCount int) string {

	if avgOrderAmount.GreaterThanOrEqual(decimal.NewFromInt(500)) &&
		totalOrderCount >= 10 {
		return "高"
	} else if avgOrderAmount.GreaterThanOrEqual(decimal.NewFromInt(200)) &&
		totalOrderCount >= 3 {
		return "中"
	} else {
		return "低"
	}
}
```

**延伸思考**：
1. 如何保护用户隐私（GDPR合规）？
2. 画像准确性如何评估？

---

##### 递进追问

- 哪些步骤必须同步确认，哪些步骤可以通过事件最终一致？
- 在重试、并发和下游不可用时，如何保证状态可恢复、可追踪？
- 规模扩大十倍后，热点、容量、隔离和降级策略如何变化？

##### 常见失分点

- 混淆领域事实、派生读模型和流程状态。
- 只描述成功路径，遗漏幂等、对账、补偿或人工处理入口。
- 把缓存、消息队列或搜索索引错误地当作交易权威来源。


#### 19. 为什么不能把 100 万酒店同步设计成一个单进程长循环？

##### 题干与约束

为什么不能把 100 万酒店同步设计成一个单进程长循环？

##### 答案骨架


参考回答：因为任务运行时间长，中途机器重启、供应商超时、进程发布、网络抖动的概率都很高。单进程长循环的进度通常在内存里，失败后只能从头跑，排查也困难。更合理的设计是 `Task + Batch + Checkpoint + DLQ`：任务先落库，执行过程持续推进 checkpoint，失败数据进入 DLQ，机器重启后从 checkpoint 恢复。

##### 递进追问

- 哪些步骤必须同步确认，哪些步骤可以通过事件最终一致？
- 在重试、并发和下游不可用时，如何保证状态可恢复、可追踪？
- 规模扩大十倍后，热点、容量、隔离和降级策略如何变化？

##### 常见失分点

- 混淆领域事实、派生读模型和流程状态。
- 只描述成功路径，遗漏幂等、对账、补偿或人工处理入口。
- 把缓存、消息队列或搜索索引错误地当作交易权威来源。


#### 20. Task 和 Batch 有什么区别？

##### 题干与约束

Task 和 Batch 有什么区别？

##### 答案骨架


参考回答：Task 是任务定义，描述“同步什么、怎么同步、什么时候同步”，比如某供应商酒店全量同步；Batch 是一次具体执行，描述“这一次跑到了哪里、成功多少、失败多少、当前 worker 是谁、租约什么时候过期”。一个 Task 会产生多次 Batch。

##### 递进追问

- 哪些步骤必须同步确认，哪些步骤可以通过事件最终一致？
- 在重试、并发和下游不可用时，如何保证状态可恢复、可追踪？
- 规模扩大十倍后，热点、容量、隔离和降级策略如何变化？

##### 常见失分点

- 混淆领域事实、派生读模型和流程状态。
- 只描述成功路径，遗漏幂等、对账、补偿或人工处理入口。
- 把缓存、消息队列或搜索索引错误地当作交易权威来源。


#### 21. Checkpoint 是什么，什么时候更新？

##### 题干与约束

Checkpoint 是什么，什么时候更新？

##### 答案骨架


参考回答：Checkpoint 是任务进度水位，例如当前城市、页码、供应商 cursor、最后处理成功的供应商酒店 ID。它用于断点续跑。推荐先处理本页数据，再推进 checkpoint。这样即使机器在中间宕机，最多重复处理上一页，不会跳过未处理数据。

##### 递进追问

- 哪些步骤必须同步确认，哪些步骤可以通过事件最终一致？
- 在重试、并发和下游不可用时，如何保证状态可恢复、可追踪？
- 规模扩大十倍后，热点、容量、隔离和降级策略如何变化？

##### 常见失分点

- 混淆领域事实、派生读模型和流程状态。
- 只描述成功路径，遗漏幂等、对账、补偿或人工处理入口。
- 把缓存、消息队列或搜索索引错误地当作交易权威来源。


#### 22. worker 如何抢占任务？

##### 题干与约束

worker 如何抢占任务？

##### 答案骨架


参考回答：通过数据库 CAS 抢占。worker 执行一条带条件的 `UPDATE`，只有 `status=PENDING` 或 `status=RUNNING AND lease_until < NOW()` 的 batch 才能被抢占。`rows_affected=1` 才说明抢占成功，其他 worker 必须退出。

##### 递进追问

- 哪些步骤必须同步确认，哪些步骤可以通过事件最终一致？
- 在重试、并发和下游不可用时，如何保证状态可恢复、可追踪？
- 规模扩大十倍后，热点、容量、隔离和降级策略如何变化？

##### 常见失分点

- 混淆领域事实、派生读模型和流程状态。
- 只描述成功路径，遗漏幂等、对账、补偿或人工处理入口。
- 把缓存、消息队列或搜索索引错误地当作交易权威来源。


#### 23. `worker_id` 和 `lease_token` 的区别是什么？

##### 题干与约束

`worker_id` 和 `lease_token` 的区别是什么？

##### 答案骨架


参考回答：`worker_id` 标识执行器实例，通常由服务名、机器名或容器名、进程号、启动时间组成，方便排查和监控。`lease_token` 标识一次抢占行为，每次抢占都重新生成。关键写操作必须同时校验 `batch_id + worker_id + lease_token`，防止旧 worker 恢复后覆盖新 worker 的进度。

##### 递进追问

- 哪些步骤必须同步确认，哪些步骤可以通过事件最终一致？
- 在重试、并发和下游不可用时，如何保证状态可恢复、可追踪？
- 规模扩大十倍后，热点、容量、隔离和降级策略如何变化？

##### 常见失分点

- 混淆领域事实、派生读模型和流程状态。
- 只描述成功路径，遗漏幂等、对账、补偿或人工处理入口。
- 把缓存、消息队列或搜索索引错误地当作交易权威来源。


#### 24. 心跳、租约、checkpoint 分别解决什么问题？

##### 题干与约束

心跳、租约、checkpoint 分别解决什么问题？

##### 答案骨架


参考回答：心跳说明 worker 是否还活着；租约说明当前任务执行权属于谁；checkpoint 说明任务恢复时从哪里继续。心跳正常不代表任务在前进，所以还要看 `last_checkpoint_at`。租约过期才允许新 worker 抢占，checkpoint 用于恢复位置。

##### 递进追问

- 哪些步骤必须同步确认，哪些步骤可以通过事件最终一致？
- 在重试、并发和下游不可用时，如何保证状态可恢复、可追踪？
- 规模扩大十倍后，热点、容量、隔离和降级策略如何变化？

##### 常见失分点

- 混淆领域事实、派生读模型和流程状态。
- 只描述成功路径，遗漏幂等、对账、补偿或人工处理入口。
- 把缓存、消息队列或搜索索引错误地当作交易权威来源。


#### 25. 机器重启后怎么恢复？

##### 题干与约束

机器重启后怎么恢复？

##### 答案骨架


参考回答：机器重启后原 worker 不再续租，`lease_until` 到期。新 worker 通过 CAS 抢占过期 batch，读取 `end_checkpoint`，从对应城市、页码或 cursor 继续。由于可能重复处理上一页，所以落库必须基于 `supplier_id + supplier_resource_code + supplier_product_code` 做幂等。

##### 递进追问

- 哪些步骤必须同步确认，哪些步骤可以通过事件最终一致？
- 在重试、并发和下游不可用时，如何保证状态可恢复、可追踪？
- 规模扩大十倍后，热点、容量、隔离和降级策略如何变化？

##### 常见失分点

- 混淆领域事实、派生读模型和流程状态。
- 只描述成功路径，遗漏幂等、对账、补偿或人工处理入口。
- 把缓存、消息队列或搜索索引错误地当作交易权威来源。


#### 26. 旧 worker 在长 GC 或网络抖动后恢复了怎么办？

##### 题干与约束

旧 worker 在长 GC 或网络抖动后恢复了怎么办？

##### 答案骨架


参考回答：旧 worker 恢复后可能以为自己还拥有任务。所有续租、checkpoint、发布和结束任务的 SQL 都必须带 `worker_id + lease_token` 条件。如果更新影响行数为 0，说明租约已经丢失，旧 worker 必须停止执行，不能继续写平台表。

##### 递进追问

- 哪些步骤必须同步确认，哪些步骤可以通过事件最终一致？
- 在重试、并发和下游不可用时，如何保证状态可恢复、可追踪？
- 规模扩大十倍后，热点、容量、隔离和降级策略如何变化？

##### 常见失分点

- 混淆领域事实、派生读模型和流程状态。
- 只描述成功路径，遗漏幂等、对账、补偿或人工处理入口。
- 把缓存、消息队列或搜索索引错误地当作交易权威来源。


#### 27. 上一次任务还没跑完，又下发了一次任务怎么办？

##### 题干与约束

上一次任务还没跑完，又下发了一次任务怎么办？

##### 答案骨架


参考回答：要用显式互斥策略。默认 `SKIP_IF_RUNNING`，如果已有同 `task_code` 的 `PENDING/RUNNING` batch，新任务直接跳过；人工强制重跑可使用 `CANCEL_PREVIOUS`；只有数据范围不重叠时才允许 `ALLOW_PARALLEL`。

##### 递进追问

- 哪些步骤必须同步确认，哪些步骤可以通过事件最终一致？
- 在重试、并发和下游不可用时，如何保证状态可恢复、可追踪？
- 规模扩大十倍后，热点、容量、隔离和降级策略如何变化？

##### 常见失分点

- 混淆领域事实、派生读模型和流程状态。
- 只描述成功路径，遗漏幂等、对账、补偿或人工处理入口。
- 把缓存、消息队列或搜索索引错误地当作交易权威来源。


#### 28. 心跳正常但 checkpoint 长时间不动，说明什么？

##### 题干与约束

心跳正常但 checkpoint 长时间不动，说明什么？

##### 答案骨架


参考回答：说明 worker 还活着，但任务可能卡在某个阶段，例如供应商慢请求、对象存储写入慢、数据库锁等待、发布阻塞。此时不应立即抢占，而应告警并结合 `last_heartbeat_stage` 定位卡点。只有租约过期才允许新 worker 抢占。

##### 递进追问

- 哪些步骤必须同步确认，哪些步骤可以通过事件最终一致？
- 在重试、并发和下游不可用时，如何保证状态可恢复、可追踪？
- 规模扩大十倍后，热点、容量、隔离和降级策略如何变化？

##### 常见失分点

- 混淆领域事实、派生读模型和流程状态。
- 只描述成功路径，遗漏幂等、对账、补偿或人工处理入口。
- 把缓存、消息队列或搜索索引错误地当作交易权威来源。


#### 29. checkpoint 更新失败怎么办？

##### 题干与约束

checkpoint 更新失败怎么办？

##### 答案骨架


参考回答：如果本页处理成功但 checkpoint 更新失败，下次恢复可能重复处理本页。因此页内落库和发布必须幂等。相反，不能先更新 checkpoint 再处理数据，否则宕机会跳过未处理页面。

##### 递进追问

- 哪些步骤必须同步确认，哪些步骤可以通过事件最终一致？
- 在重试、并发和下游不可用时，如何保证状态可恢复、可追踪？
- 规模扩大十倍后，热点、容量、隔离和降级策略如何变化？

##### 常见失分点

- 混淆领域事实、派生读模型和流程状态。
- 只描述成功路径，遗漏幂等、对账、补偿或人工处理入口。
- 把缓存、消息队列或搜索索引错误地当作交易权威来源。


#### 30. 任务被人工取消时 worker 还在跑，怎么停？

##### 题干与约束

任务被人工取消时 worker 还在跑，怎么停？

##### 答案骨架


参考回答：worker 不应该只在启动时读取状态，而要在每页处理前后检查 batch status。如果发现 `CANCELLED`，停止继续拉供应商，不再发布新数据，只做必要的清理和日志记录。

##### 递进追问

- 哪些步骤必须同步确认，哪些步骤可以通过事件最终一致？
- 在重试、并发和下游不可用时，如何保证状态可恢复、可追踪？
- 规模扩大十倍后，热点、容量、隔离和降级策略如何变化？

##### 常见失分点

- 混淆领域事实、派生读模型和流程状态。
- 只描述成功路径，遗漏幂等、对账、补偿或人工处理入口。
- 把缓存、消息队列或搜索索引错误地当作交易权威来源。


#### 31. Raw Snapshot 的价值是什么？

##### 题干与约束

Raw Snapshot 的价值是什么？

##### 答案骨架


参考回答：Raw Snapshot 是供应商原始响应的证据，不是平台商品模型。它用于排查线上问题、回放同步、验证标准化规则、做 diff，也能区分是供应商数据错误还是平台映射错误。

##### 递进追问

- 哪些步骤必须同步确认，哪些步骤可以通过事件最终一致？
- 在重试、并发和下游不可用时，如何保证状态可恢复、可追踪？
- 规模扩大十倍后，热点、容量、隔离和降级策略如何变化？

##### 常见失分点

- 混淆领域事实、派生读模型和流程状态。
- 只描述成功路径，遗漏幂等、对账、补偿或人工处理入口。
- 把缓存、消息队列或搜索索引错误地当作交易权威来源。


#### 32. 为什么需要 Diff？

##### 题干与约束

为什么需要 Diff？

##### 答案骨架


参考回答：同步成功不等于应该发布。Diff 用来比较标准化后的数据和当前线上发布版本，识别字段变化、图片变化、坐标变化、房型变化和可售变化。低风险变化可以自动发布，高风险变化进入审核或 DLQ。

##### 递进追问

- 哪些步骤必须同步确认，哪些步骤可以通过事件最终一致？
- 在重试、并发和下游不可用时，如何保证状态可恢复、可追踪？
- 规模扩大十倍后，热点、容量、隔离和降级策略如何变化？

##### 常见失分点

- 混淆领域事实、派生读模型和流程状态。
- 只描述成功路径，遗漏幂等、对账、补偿或人工处理入口。
- 把缓存、消息队列或搜索索引错误地当作交易权威来源。


#### 33. DLQ 为什么建议用 MySQL，而不是只用消息队列？

##### 题干与约束

DLQ 为什么建议用 MySQL，而不是只用消息队列？

##### 答案骨架


参考回答：供应商同步失败往往不是简单消息消费失败，而是字段缺失、城市映射失败、价格异常、发布失败等需要人工修复、状态流转和审计的问题。MySQL DLQ 可以作为权威问题单，支持查询、分派、重试、忽略、修复和报表。消息队列 DLQ 可以做短期缓冲，但不适合作为运营修复台账。

##### 递进追问

- 哪些步骤必须同步确认，哪些步骤可以通过事件最终一致？
- 在重试、并发和下游不可用时，如何保证状态可恢复、可追踪？
- 规模扩大十倍后，热点、容量、隔离和降级策略如何变化？

##### 常见失分点

- 混淆领域事实、派生读模型和流程状态。
- 只描述成功路径，遗漏幂等、对账、补偿或人工处理入口。
- 把缓存、消息队列或搜索索引错误地当作交易权威来源。


#### 34. worker 可以从 Redis 中抢占任务吗？

##### 题干与约束

worker 可以从 Redis 中抢占任务吗？

##### 答案骨架


参考回答：可以，但我会把 Redis 作为加速锁或短租约，不把它作为唯一权威状态。任务状态、checkpoint、统计、DLQ 和审计仍然落 MySQL。Redis 可以用 `SET lock_key value NX EX 300` 抢锁，用 Lua 保证续租和释放的原子性。但真正开始执行前仍要更新 MySQL batch 的 `worker_id + lease_token + lease_until`，避免 Redis 主从切换、锁丢失或网络分区导致状态不可追溯。

##### 递进追问

- 哪些步骤必须同步确认，哪些步骤可以通过事件最终一致？
- 在重试、并发和下游不可用时，如何保证状态可恢复、可追踪？
- 规模扩大十倍后，热点、容量、隔离和降级策略如何变化？

##### 常见失分点

- 混淆领域事实、派生读模型和流程状态。
- 只描述成功路径，遗漏幂等、对账、补偿或人工处理入口。
- 把缓存、消息队列或搜索索引错误地当作交易权威来源。


#### 35. 订单的消息通知设计

##### 题干与约束

订单状态变化时需要通知用户（下单成功、发货、签收）。如何设计消息通知系统？

##### 答案骨架


**问题描述**：
订单状态变化时需要通知用户（下单成功、发货、签收）。如何设计消息通知系统？

**答案**：

**通知渠道**：
1. App推送
2. 短信
3. 微信公众号/服务号
4. 站内信
5. 邮件

**推荐方案**（Go实现）：

```go
package notification

import (
	"context"
)

// NotificationService 通知服务
type NotificationService struct {
	pushSvc     PushService     // App推送
	smsSvc      SMSService      // 短信
	wechatSvc   WechatService   // 微信
	emailSvc    EmailService    // 邮件
	inboxSvc    InboxService    // 站内信
}

// NotifyOrderStatusChanged 订单状态变更通知
func (s *NotificationService) NotifyOrderStatusChanged(ctx context.Context,
	order *Order, oldStatus, newStatus OrderStatus) error {

	// 根据状态确定通知内容
	template := s.getTemplate(newStatus)

	// 并行发送多渠道通知
	errChan := make(chan error, 5)

	// 1. App推送（必发）
	go func() {
		errChan <- s.pushSvc.Push(ctx, order.UserID, PushMessage{
			Title:   template.Title,
			Content: template.Content,
			Data:    map[string]interface{}{"order_id": order.OrderID},
		})
	}()

	// 2. 短信（重要状态才发）
	if s.shouldSendSMS(newStatus) {
		go func() {
			phone := s.getUserPhone(ctx, order.UserID)
			errChan <- s.smsSvc.Send(ctx, phone, template.SMSContent)
		}()
	} else {
		errChan <- nil
	}

	// 3. 微信（用户已绑定才发）
	go func() {
		if openID := s.getUserWechatOpenID(ctx, order.UserID); openID != "" {
			errChan <- s.wechatSvc.SendTemplateMessage(ctx, openID, template.WechatTemplate)
		} else {
			errChan <- nil
		}
	}()

	// 4. 站内信（必发）
	go func() {
		errChan <- s.inboxSvc.Create(ctx, &InboxMessage{
			UserID:  order.UserID,
			Title:   template.Title,
			Content: template.Content,
			Type:    "ORDER_UPDATE",
		})
	}()

	// 5. 邮件（用户订阅才发）
	go func() {
		if s.userHasEmailSubscription(ctx, order.UserID) {
			email := s.getUserEmail(ctx, order.UserID)
			errChan <- s.emailSvc.Send(ctx, email, template.EmailContent)
		} else {
			errChan <- nil
		}
	}()

	// 收集结果（至少一个渠道成功即可）
	successCount := 0
	for i := 0; i < 5; i++ {
		if err := <-errChan; err == nil {
			successCount++
		}
	}

	if successCount == 0 {
		return errors.New("所有通知渠道都失败")
	}

	return nil
}

// 通知模板
func (s *NotificationService) getTemplate(status OrderStatus) *NotificationTemplate {
	templates := map[OrderStatus]*NotificationTemplate{
		OrderStatusPaid: {
			Title:       "订单支付成功",
			Content:     "您的订单已支付成功，我们将尽快为您发货",
			SMSContent:  "【京东】您的订单已支付成功，预计3天内送达",
		},
		OrderStatusShipped: {
			Title:       "订单已发货",
			Content:     "您的订单已发货，快递单号：SF1234567890",
			SMSContent:  "【京东】您的订单已发货，单号SF1234567890",
		},
		OrderStatusReceived: {
			Title:       "订单已签收",
			Content:     "您的订单已签收，期待您的评价",
		},
	}

	return templates[status]
}

// 是否发送短信
func (s *NotificationService) shouldSendSMS(status OrderStatus) bool {
	// 只有关键状态发短信（控制成本）
	importantStatuses := []OrderStatus{
		OrderStatusPaid,
		OrderStatusShipped,
		OrderStatusRefunded,
	}

	for _, s := range importantStatuses {
		if s == status {
			return true
		}
	}
	return false
}
```

**延伸思考**：
1. 通知失败如何重试？
2. 如何设计通知的用户偏好设置（关闭某些通知）？
3. 大批量通知如何限流（避免骚扰）？

---

##### 递进追问

- 哪些步骤必须同步确认，哪些步骤可以通过事件最终一致？
- 在重试、并发和下游不可用时，如何保证状态可恢复、可追踪？
- 规模扩大十倍后，热点、容量、隔离和降级策略如何变化？

##### 常见失分点

- 混淆领域事实、派生读模型和流程状态。
- 只描述成功路径，遗漏幂等、对账、补偿或人工处理入口。
- 把缓存、消息队列或搜索索引错误地当作交易权威来源。


#### 36. 预授权支付的设计（酒店、租车场景）

##### 题干与约束

酒店预订需要预授权（冻结资金但不扣款），退房时根据实际消费扣款。如何设计预授权支付？

##### 答案骨架


**问题描述**：
酒店预订需要预授权（冻结资金但不扣款），退房时根据实际消费扣款。如何设计预授权支付？

**答案**：

**推荐方案**（Go实现）：

```go
// PreAuthService 预授权服务
type PreAuthService struct {
	paymentAdapter PaymentAdapter
	preAuthRepo    PreAuthRepository
}

// PreAuthorize 预授权
func (s *PreAuthService) PreAuthorize(ctx context.Context,
	req *PreAuthRequest) (*PreAuthResponse, error) {

	// 1. 创建预授权记录
	preAuth := &PreAuthorization{
		PreAuthID:  generatePreAuthID(),
		OrderID:    req.OrderID,
		UserID:     req.UserID,
		Amount:     req.Amount,  // 冻结金额
		Status:     PreAuthStatusFrozen,
		CreatedAt:  time.Now(),
		ExpireAt:   time.Now().Add(30 * 24 * time.Hour), // 30天有效期
	}

	if err := s.preAuthRepo.Create(ctx, preAuth); err != nil {
		return nil, err
	}

	// 2. 调用支付渠道预授权接口
	resp, err := s.paymentAdapter.PreAuthorize(ctx, &ThirdPartyPreAuthRequest{
		OutRequestNo: preAuth.PreAuthID,
		Amount:       req.Amount,
		ExpireTime:   preAuth.ExpireAt,
	})

	if err != nil {
		preAuth.Status = PreAuthStatusFailed
		s.preAuthRepo.Update(ctx, preAuth)
		return nil, err
	}

	// 3. 保存第三方预授权号
	preAuth.ThirdPartyID = resp.AuthNo
	s.preAuthRepo.Update(ctx, preAuth)

	return &PreAuthResponse{
		PreAuthID: preAuth.PreAuthID,
		AuthNo:    resp.AuthNo,
	}, nil
}

// Complete 完成预授权（实际扣款）
func (s *PreAuthService) Complete(ctx context.Context,
	preAuthID string, actualAmount decimal.Decimal) error {

	// 1. 查询预授权
	preAuth, err := s.preAuthRepo.FindByID(ctx, preAuthID)
	if err != nil {
		return err
	}

	// 2. 校验金额
	if actualAmount.GreaterThan(preAuth.Amount) {
		return errors.New("实际金额超过预授权金额")
	}

	// 3. 调用支付渠道完成预授权
	err = s.paymentAdapter.CompletePreAuth(ctx, &CompletePreAuthRequest{
		AuthNo: preAuth.ThirdPartyID,
		Amount: actualAmount,
	})

	if err != nil {
		return err
	}

	// 4. 更新状态
	preAuth.Status = PreAuthStatusCompleted
	preAuth.ActualAmount = actualAmount
	preAuth.CompletedAt = timePtr(time.Now())
	s.preAuthRepo.Update(ctx, preAuth)

	// 5. 多余金额解冻
	if actualAmount.LessThan(preAuth.Amount) {
		unfreezeAmount := preAuth.Amount.Sub(actualAmount)
		log.Infof("解冻多余金额: %v", unfreezeAmount)
	}

	return nil
}

// Cancel 取消预授权
func (s *PreAuthService) Cancel(ctx context.Context, preAuthID string) error {
	preAuth, err := s.preAuthRepo.FindByID(ctx, preAuthID)
	if err != nil {
		return err
	}

	// 调用支付渠道取消预授权
	err = s.paymentAdapter.CancelPreAuth(ctx, preAuth.ThirdPartyID)
	if err != nil {
		return err
	}

	preAuth.Status = PreAuthStatusCancelled
	s.preAuthRepo.Update(ctx, preAuth)

	return nil
}
```

**延伸思考**：
1. 预授权过期如何自动解冻？
2. 预授权场景下的对账如何设计？

---

---

##### 递进追问

- 哪些步骤必须同步确认，哪些步骤可以通过事件最终一致？
- 在重试、并发和下游不可用时，如何保证状态可恢复、可追踪？
- 规模扩大十倍后，热点、容量、隔离和降级策略如何变化？

##### 常见失分点

- 混淆领域事实、派生读模型和流程状态。
- 只描述成功路径，遗漏幂等、对账、补偿或人工处理入口。
- 把缓存、消息队列或搜索索引错误地当作交易权威来源。


#### 37. AI Agent 高并发架构

##### 题干与约束
设计一个面对高并发请求、长推理时间与有限模型成本的 AI Agent 服务。

##### 答案骨架
**挑战**：LLM 推理慢（秒级）、显存/线程池易耗尽、Token 成本高。

**优化策略**：
- **全异步化**：请求 → MQ → Agent 消费 → 结果存储 → 前端 SSE 推送。
- **流式输出 (SSE)**：Token 级返回，降低首屏感知延迟。
- **语义缓存 (Semantic Cache)**：向量相似度匹配高频问题，直接返回缓存。
- **成本优化**：模型蒸馏（小模型处理简单请求）；KV Cache 复用；请求批处理 (Batching)。
- **限流熔断**：严格限制 Agent 调用内部工具接口的频率，防止 AI 攻击内部系统。

---

### 二、海量数据与存储


#### 38. 短链接服务

##### 题干与约束
设计一个支持短链生成、跳转、过期和访问统计的服务。

##### 答案骨架
**生成策略**：
- **发号器 + Base62**：分布式 ID → 62 进制编码（a-z, A-Z, 0-9），6 位可表示 $62^6$ ≈ 568 亿。
- Hash（MD5/Murmur）取前 N 位：简单但需处理冲突。

**重定向选择**：
- **301 永久重定向**：浏览器缓存，无法统计点击数。
- **302 临时重定向**：每次经过服务端，可统计 UA、IP、Referer 等点击来源。

**点击统计**：302 重定向时解析 UA/IP/渠道 → 异步写入日志 → Flink 聚合 → ClickHouse 存储。

---


#### 39. Feed 流

##### 题干与约束
设计一个支持关注关系、内容发布和个性化时间线的 Feed 系统。

##### 答案骨架
| 模式 | 读性能 | 写性能 | 适用场景 |
|------|--------|--------|----------|
| **推 (Write-fanout)** | 快 | 慢（写 N 个粉丝收件箱） | 普通用户 |
| **拉 (Read-fanout)** | 慢（聚合 N 个关注人） | 快 | 大 V |
| **推拉结合** | 均衡 | 均衡 | **业界主流** |

**推拉结合策略**：
- 活跃用户 / 普通博主：推模式。
- 大 V / 僵尸粉：拉模式。

**已读去重**：用户维度维护 RoaringBitmap，推送前 `if (!bitmap.contains(postId)) push()`。

---


#### 40. 评论系统

##### 题干与约束
设计一个支持评论、回复、排序、审核和高并发读取的评论系统。

##### 答案骨架
**存储模型对比**：

| 模型 | 原理 | 优点 | 缺点 |
|------|------|------|------|
| **邻接表** | `id, parent_id` | 简单 | 查子树需递归，性能差 |
| **路径枚举** | `id, path="1/2/5"` | 前缀查询方便 | 路径长度受限 |
| **闭包表** | 单独表存所有祖先-后代 | 查询极快 | 写入量大 |

**业界主流（两层结构）**：
- **一级评论**：按热度/时间排序（Redis ZSet 或 DB 索引）。
- **二级回复**：扁平化存储。`parent_id` 指向一级评论，`reply_to_id` 指向被回复的人。不做无限嵌套。

**防灌水**：发言频率限制 → 敏感词过滤（AC 自动机）→ 举报+审核队列 → 新用户评论需审核（信任分体系）。

---


#### 41. 即时通讯系统

##### 题干与约束
设计一个支持一对一和群组会话、在线消息、离线补发、已读状态和多端登录的即时通讯系统。

##### 答案骨架
1. 用户通过长连接网关接入，连接路由层维护用户设备到网关节点的临时映射。
2. 消息服务鉴权并校验会话成员，写入持久化消息日志后返回服务端消息序号。
3. 按会话分区保证单会话内顺序，消息事件异步扇出到在线设备并持久化离线游标。
4. 客户端按会话游标拉取缺失消息，发送端使用客户端幂等键处理重试和重复提交。
5. 群聊按规模选择写扩散或读扩散；大型群组限制在线扇出并提供批量投递。

##### 关键决策
- 先定义消息送达、已读和在线状态的语义与保留期限。
- 短暂网络断连通过游标补拉收敛，不依赖网关内存作为唯一消息状态。

##### 故障与追问
网关节点宕机后客户端重连其他节点，按最后确认游标补收；持久化失败时不得向发送方确认消息已可靠接收。


#### 42. 视频点播与直播平台

##### 题干与约束
设计一个支持用户上传、转码、点播播放和直播观看的视频平台。

##### 答案骨架
1. 上传服务分配分片上传会话，原始视频先进入对象存储和待处理队列。
2. 转码工作流生成多码率切片、清单和缩略图，任务可重试且按内容版本幂等。
3. 点播通过 CDN 分发分段媒体文件，根据网络质量自适应切换码率。
4. 直播入口接收推流，实时转码后以低延迟协议分发；热点直播可预热边缘节点。
5. 播放服务记录会话、错误和卡顿指标，用异步日志支持内容分析和容量规划。

##### 关键决策
- 上传处理、转码和播放解耦，避免转码积压阻塞点播。
- 根据互动延迟要求选择直播协议，并明确画质、延迟和 CDN 成本取舍。

##### 故障与追问
转码失败保留源文件并支持重新排队；区域 CDN 故障时切换备用源站并限制回源并发。


#### 43. 网约车派单与司机调度系统

##### 题干与约束
设计一个将乘客出行请求匹配给合适司机的派单系统，要求控制等待时间、重复派单和司机状态冲突。

##### 答案骨架
1. 司机端周期上报位置与可接单状态，位置索引按地理网格分桶并设置新鲜度。
2. 订单服务校验乘客、起终点和服务规则，生成带版本的派单任务。
3. 调度器按距离、预计到达时间、车型和公平性从邻近网格召回候选司机。
4. 司机接单使用带过期时间的原子占用或版本比较，确保同一时刻只接受一个有效订单。
5. 派单失败扩大搜索范围或进入人工/批量兜底队列，并记录接受率与等待时间。

##### 关键决策
- 位置数据是近实时读模型，接单状态必须有权威状态迁移。
- 候选召回与最终派单分离，避免对全部司机做昂贵全局扫描。

##### 故障与追问
司机网络延迟造成重复接单时，以订单状态版本和幂等请求收敛；定位数据过期时不参与自动派单。


#### 44. 酒店预订与房态管理系统

##### 题干与约束
设计一个支持多酒店、多房型和日期库存的预订平台，要求避免同一房晚被重复确认。

##### 答案骨架
1. 酒店、房型、房价计划和每日房态分别建模，明确库存权威来源及供应商更新时间。
2. 查询使用按酒店、房型、日期组织的读模型；下单前对每个房晚执行库存预占。
3. 预订创建幂等并生成短期 hold，支付或担保成功后确认；超时释放 hold。
4. 跨多个日期的预订定义全有或部分成功语义，失败时释放已预占房晚。
5. 渠道回调通过版本、幂等键和对账任务处理重复、乱序和未知结果。

##### 关键决策
- 读可容忍有限延迟，确认预订必须以库存账本或供应商确认结果为准。
- 明确免费取消、部分取消、改期和供应商超售的补偿边界。

##### 故障与追问
供应商确认超时不能直接当作失败；进入处理中状态并查询或对账，避免重复扣款和重复预订。


#### 45. 网络爬虫系统

##### 题干与约束
设计一个遵循抓取策略、支持大规模 URL 调度、去重、抓取和索引更新的网络爬虫。

##### 答案骨架
1. 种子 URL 进入持久化 frontier，按域名和优先级排队并执行 robots 与访问频率策略。
2. URL 规范化后使用精确索引或 Bloom Filter 做候选去重，避免重复入队。
3. 抓取 Worker 通过域名租约领取任务，执行超时、重试和内容大小限制。
4. 解析器提取链接和内容，存储原始响应及版本，再将结构化文档送入索引管道。
5. 以最后抓取时间、错误率和内容变化决定重抓优先级，提供域名封禁与删除机制。

##### 关键决策
- 按域名限速和 robots 约束优先于吞吐最大化。
- 去重索引、任务队列和文档库分层，确保 Worker 崩溃后可恢复。

##### 故障与追问
目标站点超时或返回异常时采用有上限的指数退避；同一域名故障时暂停该分区，避免重试风暴。


#### 46. 协同文档编辑系统

##### 题干与约束
设计一个支持多人同时编辑、离线修改、权限管理、历史版本和实时协作的文档系统。

##### 答案骨架
1. 编辑端提交带文档版本、用户和操作序号的增量操作，协作服务鉴权后写入操作日志。
2. 使用 OT 或 CRDT 合并并发编辑，明确字符位置、删除和格式操作的冲突语义。
3. 在线协作者通过 WebSocket 接收增量，断线后按游标补拉，超出窗口则加载快照。
4. 定期生成压缩快照并保留版本历史，文档元数据与操作日志分层存储。
5. 按文档和组织执行读写权限校验，记录敏感分享、导出和管理员操作。

##### 关键决策
- 协作合并算法必须与离线重放和版本兼容策略一起设计。
- 长文档使用增量同步和快照压缩，避免每次传输全量内容。

##### 故障与追问
客户端长期离线后提交旧格式操作时先进行版本迁移或拒绝并提示重载；快照失败可从操作日志重建。


#### 47. IoT 设备遥测接入平台

##### 题干与约束
设计一个接入海量设备遥测数据的平台，要求安全认证、流量削峰、实时告警和历史查询。

##### 答案骨架
1. 设备使用可轮换凭据接入网关，连接层校验设备身份、主题权限和消息大小。
2. 接入服务按设备或租户做速率限制，将遥测写入分区消息流并记录事件时间。
3. 流处理执行去重、窗口聚合、异常检测和规则告警；迟到数据按业务容忍度补算。
4. 热数据进入时序存储支持近期查询，长期数据压缩归档到低成本存储。
5. 管理面维护设备注册、固件版本、影子状态和凭据撤销，数据面独立扩缩容。

##### 关键决策
- 设备上报至少一次时，消费侧按设备 ID 和序列号去重。
- 按租户、公有云区域和设备组隔离配额，保护共享接入集群。

##### 故障与追问
断网设备恢复后可能批量补发旧数据；按事件时间处理并限制补传速率，避免挤占实时告警链路。


## 4. 数据建模、一致性与数据处理

#### 48. 主数据、流程对象和交易快照如何区分？

**题型：** 快问快答，5 分钟
**预期结论：** 正式商品主数据服务于当前交易契约；Draft、Staging、QC 和任务是供给流程对象；订单保存创建当时的商品、报价、履约和退款快照。
**适用边界：** 小型系统可以共库，但仍需在模型和状态机上明确这三类事实，避免未审核数据进入交易读取路径。


#### 49. 订单数据的分库分表设计

##### 题干与约束

订单表数据量达到亿级，单表查询性能下降。如何设计订单的分库分表方案？

##### 答案骨架


**问题描述**：
订单表数据量达到亿级，单表查询性能下降。如何设计订单的分库分表方案？

**答案**：

**问题分析**：
订单分库分表的核心要素：
1. 分片键选择（user_id还是order_id）
2. 分片数量（16、32、64、128）
3. 跨片查询（如运营查询某时间段订单）
4. 数据扩容

**方案一：按user_id分片（推荐）**

核心思想：
同一用户的订单存储在同一分片。

分片规则：
```go
// 分片数量
const ShardCount = 64

// 计算分片
func GetShardIndex(userID int64) int {
	return int(userID % ShardCount)
}

// 路由到数据源
func GetDataSource(userID int64) *sql.DB {
	shardIndex := GetShardIndex(userID)
	return dataSources[shardIndex]
}
```

表结构：
```sql
-- 64个库，每个库有orders表
database_00.orders
database_01.orders
...
database_63.orders

订单ID生成：
order_id = snowflake_id
不包含分片信息（通过user_id路由）
```

优点：
- 用户维度查询高效（"我的订单"）
- 单用户订单聚合容易
- 避免跨库JOIN

缺点：
- 按订单ID查询需要广播（查所有分片）
- 数据可能不均匀（大客户订单多）

**方案二：按order_id分片**

核心思想：
按订单ID散列分片。

分片规则：
```go
func GetShardIndex(orderID int64) int {
	return int(orderID % ShardCount)
}
```

订单ID生成（包含分片信息）：
```go
// 订单ID结构：分片位 + Snowflake ID
// 前6位：分片号（0-63）
// 后13位：Snowflake ID

func GenerateOrderID(userID int64) int64 {
	shardIndex := GetShardIndex(userID)
	snowflakeID := snowflake.Generate()

	// 组装：分片号（6位） + snowflake（13位）
	return int64(shardIndex)*1e13 + snowflakeID
}

// 解析分片
func ParseShard(orderID int64) int {
	return int(orderID / 1e13)
}
```

优点：
- 按订单ID查询高效（直接定位分片）
- 数据均匀

缺点：
- 用户维度查询需要广播
- "我的订单"查询慢

**方案三：复合分片**

核心思想：
主表按user_id分片，建立order_id到分片的映射表。

设计：
```text
主表（按user_id分片）：
shard_00.orders
shard_01.orders

映射表（不分片，单独集群）：
order_routing
├── order_id（主键）
├── shard_index（分片号）
└── user_id

查询流程：
1. 按订单ID查询：
   - 查询order_routing获取分片号
   - 路由到对应分片查询

2. 按用户ID查询：
   - 直接路由到用户分片
```

优点：
- 支持多种查询方式
- 灵活

缺点：
- 映射表是单点
- 实现复杂

**方案对比**：

| 方案 | 用户查询 | 订单查询 | 数据均匀度 | 实施难度 |
|------|---------|---------|-----------|---------|
| 按user_id | ★★★★★ | ★★☆☆☆ | ★★★☆☆ | ★★★★☆ |
| 按order_id | ★★☆☆☆ | ★★★★★ | ★★★★★ | ★★★★☆ |
| 复合分片 | ★★★★★ | ★★★★★ | ★★★★★ | ★★☆☆☆ |

**推荐方案**：
采用**按user_id分片**。

实施要点（Go实现）：

1. **分片路由中间件**：
   ```go
   package sharding

   import (
	"context"
	"database/sql"
   )

   // ShardingManager 分片管理器
   type ShardingManager struct {
	dataSources []*sql.DB
	shardCount  int
   }

   // NewShardingManager 创建分片管理器
   func NewShardingManager(dsns []string) (*ShardingManager, error) {
	dbs := make([]*sql.DB, len(dsns))
	for i, dsn := range dsns {
		db, err := sql.Open("mysql", dsn)
		if err != nil {
			return nil, err
		}
		dbs[i] = db
	}

	return &ShardingManager{
		dataSources: dbs,
		shardCount:  len(dsns),
	}, nil
   }

   // GetDB 根据用户ID获取数据库连接
   func (sm *ShardingManager) GetDB(userID int64) *sql.DB {
	shardIndex := userID % int64(sm.shardCount)
	return sm.dataSources[shardIndex]
   }

   // ExecuteOnShard 在指定分片执行查询
   func (sm *ShardingManager) ExecuteOnShard(ctx context.Context, userID int64,
	fn func(*sql.DB) error) error {
	db := sm.GetDB(userID)
	return fn(db)
   }

   // Broadcast 广播到所有分片执行
   func (sm *ShardingManager) Broadcast(ctx context.Context,
	fn func(*sql.DB) error) []error {
	errors := make([]error, 0)
	for _, db := range sm.dataSources {
		if err := fn(db); err != nil {
			errors = append(errors, err)
		}
	}
	return errors
   }
   ```

2. **订单Repository实现**：
   ```go
   type OrderRepository struct {
	shardingMgr *ShardingManager
   }

   // Create 创建订单
   func (r *OrderRepository) Create(ctx context.Context, order *Order) error {
	return r.shardingMgr.ExecuteOnShard(ctx, order.UserID, func(db *sql.DB) error {
		query := `INSERT INTO orders (order_id, user_id, total_amount, status, created_at)
		          VALUES (?, ?, ?, ?, ?)`
		_, err := db.ExecContext(ctx, query,
			order.OrderID, order.UserID, order.TotalAmount,
			order.Status, time.Now())
		return err
	})
   }

   // FindByUserID 查询用户订单（单分片）
   func (r *OrderRepository) FindByUserID(ctx context.Context, userID int64,
	page, size int) ([]*Order, error) {
	var orders []*Order

	err := r.shardingMgr.ExecuteOnShard(ctx, userID, func(db *sql.DB) error {
		query := `SELECT * FROM orders
		          WHERE user_id=?
		          ORDER BY created_at DESC
		          LIMIT ? OFFSET ?`
		rows, err := db.QueryContext(ctx, query, userID, size, (page-1)*size)
		if err != nil {
			return err
		}
		defer rows.Close()

		for rows.Next() {
			order := &Order{}
			// 扫描数据...
			orders = append(orders, order)
		}
		return nil
	})

	return orders, err
   }

   // FindByOrderID 按订单ID查询（需要广播）
   func (r *OrderRepository) FindByOrderID(ctx context.Context, orderID int64) (*Order, error) {
	// 方案1：广播到所有分片查询（慢）
	for _, db := range r.shardingMgr.dataSources {
		order, err := queryFromDB(db, orderID)
		if err == nil && order != nil {
			return order, nil
		}
	}
	return nil, ErrOrderNotFound

	// 方案2：维护order_id -> user_id映射（推荐）
	// userID := r.getOrderUserMapping(orderID)
	// return r.FindByUserAndOrderID(ctx, userID, orderID)
   }
   ```

3. **订单ID包含分片信息**：
   ```go
   // 订单ID结构：6位分片号 + 13位Snowflake

   func GenerateOrderIDWithShard(userID int64) int64 {
	shardIndex := userID % ShardCount
	snowflakeID := snowflake.NextID()

	// 组装：前6位是分片号
	return shardIndex*1e13 + snowflakeID
   }

   // 解析分片号
   func ParseShardFromOrderID(orderID int64) int {
	return int(orderID / 1e13)
   }

   // 直接定位查询
   func (r *OrderRepository) FindByOrderIDFast(ctx context.Context, orderID int64) (*Order, error) {
	shardIndex := ParseShardFromOrderID(orderID)
	db := r.shardingMgr.dataSources[shardIndex]

	query := `SELECT * FROM orders WHERE order_id=?`
	row := db.QueryRowContext(ctx, query, orderID)

	order := &Order{}
	err := row.Scan(&order.OrderID, &order.UserID, ...)
	return order, err
   }
   ```

4. **扩容方案**：
   ```
   扩容策略（64 → 128分片）：

   方案A：双写期
   1. 新建64个分片（总共128个）
   2. 新订单写入新分片规则
   3. 老订单保留在老分片
   4. 查询时先查新分片，未命中再查老分片

   方案B：一致性哈希
   1. 使用一致性哈希算法
   2. 扩容时只需迁移部分数据
   3. 数据迁移期间双写
   ```

**延伸思考**：
1. 如何设计分库分表的全局查询（如运营后台）？
2. 订单归档如何设计（冷热数据分离）？
3. 分库分表如何支持跨库JOIN？

---

##### 递进追问

- 哪些步骤必须同步确认，哪些步骤可以通过事件最终一致？
- 在重试、并发和下游不可用时，如何保证状态可恢复、可追踪？
- 规模扩大十倍后，热点、容量、隔离和降级策略如何变化？

##### 常见失分点

- 混淆领域事实、派生读模型和流程状态。
- 只描述成功路径，遗漏幂等、对账、补偿或人工处理入口。
- 把缓存、消息队列或搜索索引错误地当作交易权威来源。


#### 50. 跨域创单的一致性边界

**题型：** 核心案例，45 分钟
**目标：** 设计包含库存预占、优惠资格锁定、订单创建和支付确认的交易链路。

##### 不可协商约束

- 订单、库存、营销和支付分别拥有自己的权威状态。
- 客户端超时不代表请求失败；任何命令和事件都可能重复投递。
- 搜索、消息通知和报表可以最终一致，但交易承诺不能靠缓存或消息本身证明。

##### 关键决策

1. 哪些状态迁移同步完成，哪些副作用通过 Outbox 传播。
2. 每个域如何定义幂等键、状态前置条件和可重放事件。
3. 补偿失败、未知支付结果和长期悬挂预约由谁发现、谁修复。

##### 故障注入

订单已落库、库存预约超时未知、优惠券锁定成功。说明用户可见状态、后台任务和最终收敛路径。


#### 51. 发布后的读模型一致性

**题型：** 核心案例，30 分钟
**目标：** 商品或配置发布后，保证详情页缓存、搜索索引和计价上下文在可接受时间内收敛。

##### 不可协商约束

- 正式主数据、版本和待发布事件必须在同一持久化边界提交。
- 搜索和缓存是派生读模型；其刷新失败不得回滚已提交的业务事实。
- 读模型必须能识别版本落后，并可从权威快照重建。

##### 关键决策

1. 发布版本、事件 ID 和投影幂等条件如何设计。
2. 删除缓存、异步刷新和全量重建各自负责什么。
3. 何时允许用户读旧数据，何时必须绕过读模型。

##### 故障注入

发布已成功，但搜索消费者连续失败一小时且缓存命中旧版本。说明诊断路径、补偿策略和用户影响控制。


#### 52. 为什么核心交易状态要有权威来源？

##### 题干与约束
订单、支付、库存热路径使用缓存时，如何解释权威状态与修复策略？
##### 答案骨架
交易状态必须有可审计、可约束、可恢复的权威来源；缓存承担低延迟、热点拦截或短期预扣，不能替代账本与状态机。发生偏差时以权威记录为准，通过事件重放、对账任务、补偿和告警追平。
##### 递进追问
缓存预扣成功、权威写入失败时，用户和库存分别如何处理？
##### 常见失分点
宣称缓存天然强一致；没有对账；把最终一致当作不处理失败。


#### 53. 系统设计题中如何回答一致性问题？

##### 题干与约束
如何避免把强一致和最终一致说成空泛口号？
##### 答案骨架
订单提交、支付状态和库存确认等资损敏感事实需要强约束或同步确认；搜索、推荐、报表等派生读模型通常允许最终一致。最终一致必须说明延迟目标、可靠投递、重放幂等、对账和人工修复，而不是只说异步。
##### 递进追问
支付已成功但订单状态尚未更新时，什么数据对用户可见，谁负责补偿？
##### 常见失分点
所有链路都强一致；所有异步都最终一致；没有时间边界和修复责任。


#### 54. 为什么核心交易状态通常放在 MySQL？

##### 题干与约束
解释为什么订单、支付和库存流水通常以 MySQL 承载权威状态。
##### 答案骨架
核心交易需要原子更新、唯一约束、状态机校验、审计和恢复能力，因此以关系型事务存储承载权威事实。缓存用于加速与削峰，消息用于传播副作用；它们都不能替代最终状态的可验证来源。
##### 递进追问
数据库成为瓶颈后，怎样扩展而不把权威状态交给缓存？
##### 常见失分点
把 MySQL 说成所有数据的唯一选择；忽略读写分离、分片和归档；把消息当存储替代品。


#### 55. 缓存和数据库不一致怎么办？

##### 题干与约束
核心数据更新后，缓存删除或刷新可能失败，业务允许的不一致窗口有限。
##### 答案骨架
通常采用缓存旁路：写入权威存储成功后删除缓存，读取未命中时回源重建，并设置合理过期。对更敏感的数据可使用消息驱动刷新、延迟删除、版本号或直接读权威存储；删除失败必须重试、告警和补偿，不能承诺绝对一致。
##### 递进追问
更新成功但删除缓存失败，怎样避免陈旧数据长期存在？
##### 常见失分点
先删缓存再写库且不处理失败；读写都强制同步更新缓存；没有过期和补偿。


#### 56. 分布式锁能解决所有并发问题吗？

##### 题干与约束
多个节点并发修改库存或订单状态，团队希望统一使用分布式锁。
##### 答案骨架
分布式锁只能降低特定临界区的并发冲突，还会面对超时、续租、误释放、主从切换和网络分区。资金、库存和状态流转应以唯一约束、条件更新、版本号和状态机为最终保护；锁可作为优化，业务操作仍必须幂等。
##### 递进追问
持锁节点长时间停顿后恢复，如何防止它覆盖新持锁者的结果？
##### 常见失分点
把锁当事务；不设置业务幂等；只讨论获取锁，不讨论失锁和释放。


#### 57. 分布式事务的几种实现方案对比

##### 题干与约束

请对比2PC、TCC、Saga、本地消息表这几种分布式事务方案，并说明在电商系统中各自的适用场景。

##### 答案骨架


**问题描述**：
请对比2PC、TCC、Saga、本地消息表这几种分布式事务方案，并说明在电商系统中各自的适用场景。

**答案**：

**问题分析**：
分布式事务方案的核心差异：
1. 一致性强度（强一致 vs 最终一致）
2. 性能开销（锁定时间、网络开销）
3. 实现复杂度（接口数量、补偿逻辑）
4. 适用场景（金融 vs 电商）

**方案一：2PC（Two-Phase Commit）**

核心思想：
分为准备阶段和提交阶段，由协调者统一协调。

流程：
```text
准备阶段（Prepare）：
协调者 → 所有参与者：准备事务
参与者 → 锁定资源，记录日志
参与者 → 协调者：返回YES/NO

提交阶段（Commit）：
如果所有参与者返回YES：
  协调者 → 所有参与者：提交事务
  参与者 → 释放资源，返回ACK
如果任一参与者返回NO：
  协调者 → 所有参与者：回滚事务
```

优点：
- 强一致性
- 原理简单

缺点：
- 性能差（两次网络往返）
- 阻塞（参与者锁定资源）
- 单点故障（协调者宕机）
- 不适合微服务

适用场景：
- 数据库分布式事务
- 小规模系统
- 对一致性要求极高且并发不高的场景

**方案二：TCC（Try-Confirm-Cancel）**

核心思想：
每个服务提供三个接口：Try、Confirm、Cancel。

流程：
```text
Try阶段：
- 订单服务：tryCreateOrder（创建订单，状态TRYING）
- 库存服务：tryReserveInventory（预占库存）
- 支付服务：tryPreparePayment（冻结金额）

全部成功 → Confirm阶段：
- 订单服务：confirmCreateOrder（状态CONFIRMED）
- 库存服务：confirmReserveInventory（确认扣减）
- 支付服务：confirmPreparePayment（确认扣款）

任一失败 → Cancel阶段：
- 订单服务：cancelCreateOrder（取消订单）
- 库存服务：cancelReserveInventory（释放库存）
- 支付服务：cancelPreparePayment（解冻金额）
```

优点：
- 强一致性
- 业务语义清晰
- 资源锁定明确

缺点：
- 实现复杂（每个服务3个接口）
- Try阶段占用资源时间长
- 需要考虑幂等性

适用场景：
- 金融交易（转账、支付）
- 核心交易链路
- 对一致性要求极高的场景

**方案三：Saga**

核心思想：
将长事务拆分为多个本地事务，失败时执行补偿。

流程：
```text
正向流程：
T1: 创建订单 → T2: 扣减库存 → T3: 扣除积分 → T4: 创建支付

失败补偿：
T4失败 → C3: 返还积分 → C2: 释放库存 → C1: 取消订单
```

优点：
- 最终一致性
- 性能好（异步）
- 实现相对简单

缺点：
- 补偿逻辑复杂
- 隔离性弱（中间状态可见）
- 需要考虑补偿失败

适用场景：
- 电商订单流程
- 长流程业务
- 可接受最终一致性的场景

**方案四：本地消息表**

核心思想：
利用本地事务保证消息发送，通过消息驱动下游操作。

流程：
```text
1. 订单服务：
   BEGIN TRANSACTION
     INSERT INTO orders ...
     INSERT INTO outbox_messages (event: OrderCreated)
   COMMIT

2. 消息发送器：
   定时扫描outbox_messages
   发送到MQ
   标记为已发送

3. 库存服务：
   监听MQ OrderCreated事件
   扣减库存
   发送InventoryReduced事件

4. 订单服务：
   监听InventoryReduced事件
   更新订单状态
```

优点：
- 实现简单
- 消息可靠性高
- 无锁，性能好

缺点：
- 最终一致性
- 需要扫描任务
- 消息顺序性

适用场景：
- 异步通知场景
- 跨系统数据同步
- 对实时性要求不高的场景

**方案对比**：

| 方案 | 一致性 | 性能 | 复杂度 | 隔离性 | 适用场景 |
|------|--------|------|--------|--------|----------|
| 2PC | 强一致 | ★☆☆☆☆ | ★★☆☆☆ | ★★★★★ | 数据库事务 |
| TCC | 强一致 | ★★☆☆☆ | ★★★★★ | ★★★★☆ | 金融交易 |
| Saga | 最终一致 | ★★★★☆ | ★★★☆☆ | ★★☆☆☆ | 电商订单 |
| 本地消息表 | 最终一致 | ★★★★★ | ★★★★☆ | ★★☆☆☆ | 异步通知 |

**推荐方案**：
电商系统不同场景使用不同方案：
- **订单创建流程**：Saga（性能和一致性平衡）
- **支付流程**：TCC（强一致性）
- **数据同步**：本地消息表（异步解耦）
- **库存扣减**：预占机制（类似TCC）

**延伸思考**：
1. 为什么电商系统很少用2PC？
2. TCC的Try阶段如何设计才能保证性能？
3. Saga的补偿操作如何保证一定成功？

---

##### 递进追问

- 哪些步骤必须同步确认，哪些步骤可以通过事件最终一致？
- 在重试、并发和下游不可用时，如何保证状态可恢复、可追踪？
- 规模扩大十倍后，热点、容量、隔离和降级策略如何变化？

##### 常见失分点

- 混淆领域事实、派生读模型和流程状态。
- 只描述成功路径，遗漏幂等、对账、补偿或人工处理入口。
- 把缓存、消息队列或搜索索引错误地当作交易权威来源。


#### 58. 幂等性设计的最佳实践

##### 题干与约束

在分布式系统中，由于网络重试、消息重复等原因，同一个请求可能被处理多次。如何设计幂等机制，保证重复请求不会产生副作用？

##### 答案骨架


**问题描述**：
在分布式系统中，由于网络重试、消息重复等原因，同一个请求可能被处理多次。如何设计幂等机制，保证重复请求不会产生副作用？

**答案**：

**问题分析**：
幂等性的核心挑战：
1. 如何识别重复请求
2. 如何防止并发重复处理
3. 如何设计幂等键
4. 幂等状态如何存储和清理

**方案一：基于唯一请求ID**

核心思想：
客户端为每个请求生成唯一ID，服务端记录已处理的ID。

实现：
```text
客户端：
POST /api/orders
Headers: {
  X-Request-Id: uuid-xxx-xxx
}
Body: {...}

服务端：
public void createOrder(OrderRequest req, String requestId) {
  // 1. 检查requestId是否已处理
  if (redis.exists("idempotent:" + requestId)) {
    return getCachedResult(requestId);
  }

  // 2. 加分布式锁（防止并发）
  if (!redis.setNX("lock:" + requestId, 1, 10)) {
    throw new ConcurrentException();
  }

  try {
    // 3. 执行业务逻辑
    Order order = orderService.create(req);

    // 4. 记录已处理+结果
    redis.setEx("idempotent:" + requestId,
                JSON.stringify(order),
                86400); // 保留24小时

    return order;
  } finally {
    redis.del("lock:" + requestId);
  }
}
```

优点：
- 实现简单
- 通用性强

缺点：
- 需要客户端配合生成requestId
- Redis存储成本

适用场景：
- API接口调用
- 用户操作（防止重复点击）

**方案二：基于业务唯一键**

核心思想：
利用业务本身的唯一性（订单号、流水号）作为幂等键。

实现：
```text
数据库设计：
CREATE TABLE orders (
  order_id VARCHAR(64) PRIMARY KEY,  -- 业务唯一键
  user_id VARCHAR(64),
  amount DECIMAL(10,2),
  status VARCHAR(20),
  UNIQUE KEY uk_user_order(user_id, external_order_id)  -- 组合唯一键
);

代码：
public Order createOrder(OrderRequest req) {
  String orderId = generateOrderId();  // 客户端提供或服务端生成

  try {
    // INSERT会因为主键冲突失败（幂等）
    db.insert("INSERT INTO orders VALUES (?, ?, ?, ?)",
              orderId, req.getUserId(), req.getAmount(), "PENDING");

    return getOrder(orderId);
  } catch (DuplicateKeyException e) {
    // 重复请求，返回已存在的订单
    return getOrder(orderId);
  }
}
```

优点：
- 不需要额外存储
- 性能好（数据库索引）
- 天然幂等

缺点：
- 需要设计业务唯一键
- 不适合更新操作

适用场景：
- 创建类操作（订单、支付）
- 有明确业务唯一键的场景

**方案三：基于状态机+版本号**

核心思想：
利用状态机和版本号，保证状态流转的幂等性。

实现：
```text
数据库设计：
CREATE TABLE orders (
  order_id VARCHAR(64) PRIMARY KEY,
  status VARCHAR(20),
  version INT DEFAULT 0,  -- 版本号
  updated_at TIMESTAMP
);

代码：
public void payOrder(String orderId) {
  // 乐观锁：只有状态为PENDING且版本匹配才更新
  int affected = db.update(
    "UPDATE orders SET status='PAID', version=version+1, updated_at=NOW() " +
    "WHERE order_id=? AND status='PENDING' AND version=?",
    orderId, currentVersion
  );

  if (affected == 0) {
    // 已经支付过了（幂等）或并发冲突
    Order order = getOrder(orderId);
    if (order.getStatus() == "PAID") {
      return; // 幂等，直接返回
    } else {
      throw new ConcurrentModificationException(); // 并发冲突，重试
    }
  }
}
```

优点：
- 不需要额外存储
- 天然解决并发问题
- 适合更新操作

缺点：
- 需要理解状态机
- 并发冲突需要重试

适用场景：
- 状态流转操作（订单状态、支付状态）
- 更新操作

**方案对比**：

| 方案 | 适用操作 | 存储成本 | 并发安全 | 实施难度 |
|------|---------|---------|---------|---------|
| 请求ID | 所有 | ★★☆☆☆ | ★★★★★ | ★★★★☆ |
| 业务唯一键 | 创建 | ★★★★★ | ★★★★★ | ★★★★★ |
| 状态机+版本号 | 更新 | ★★★★★ | ★★★★☆ | ★★★☆☆ |

**推荐方案**：
根据场景选择合适方案：
- **创建操作**：业务唯一键（如orderId）
- **更新操作**：状态机+版本号
- **通用接口**：请求ID

实施要点：

1. **幂等键设计原则**：
   - 唯一性：能唯一标识一次操作
   - 稳定性：多次请求幂等键相同
   - 业务相关：优先用业务键（orderId）而非技术键（requestId）

2. **幂等粒度**：
   ```
   粗粒度（操作级）：
   - 幂等键：orderId
   - 含义：同一订单不能重复创建

   细粒度（步骤级）：
   - 幂等键：orderId + operationType（如 "order123:pay"）
   - 含义：同一订单的支付操作不能重复
   ```

3. **幂等状态清理**：
   ```
   Redis存储：
   - 设置过期时间（24小时）
   - 定期清理过期数据

   数据库存储：
   - 不需要清理（利用业务唯一键）
   ```

4. **并发安全**：
   ```
   分布式锁：
   String lockKey = "lock:order:" + orderId;
   if (redis.setNX(lockKey, 1, 10)) {
     try {
       // 业务逻辑
     } finally {
       redis.del(lockKey);
     }
   }

   数据库乐观锁：
   UPDATE orders
   SET status=?, version=version+1
   WHERE order_id=? AND version=?
   ```

5. **幂等测试**：
   ```
   测试用例：
   1. 相同参数调用2次，验证第2次返回相同结果
   2. 并发调用2次，验证只有1次生效
   3. 延迟重试，验证中间状态不影响幂等性
   ```

**延伸思考**：
1. 如何设计支付接口的幂等性？
2. 消息队列消费端如何保证幂等性？
3. 幂等状态如何跨服务共享？

---

##### 递进追问

- 哪些步骤必须同步确认，哪些步骤可以通过事件最终一致？
- 在重试、并发和下游不可用时，如何保证状态可恢复、可追踪？
- 规模扩大十倍后，热点、容量、隔离和降级策略如何变化？

##### 常见失分点

- 混淆领域事实、派生读模型和流程状态。
- 只描述成功路径，遗漏幂等、对账、补偿或人工处理入口。
- 把缓存、消息队列或搜索索引错误地当作交易权威来源。


#### 59. 设计数据最终一致性的对账补偿机制

##### 题干与约束

在分布式系统中，虽然采用了Saga等最终一致性方案，但仍可能因为网络、重试等原因导致数据不一致。如何设计对账补偿机制？

##### 答案骨架


**问题描述**：
在分布式系统中，虽然采用了Saga等最终一致性方案，但仍可能因为网络、重试等原因导致数据不一致。如何设计对账补偿机制？

**答案**：

**问题分析**：
对账补偿的核心挑战：
1. 如何发现数据不一致
2. 如何定位不一致的根本原因
3. 如何自动补偿修复
4. 如何避免补偿引入新问题

**方案一：实时对账**

核心思想：
在关键操作后立即对账，发现问题立即修复。

设计：
```text
订单支付成功后：
1. 订单服务：更新订单状态为PAID
2. 支付服务：更新支付单状态为SUCCESS
3. 对账服务：
   - 查询订单状态
   - 查询支付单状态
   - 对比是否一致
   - 如果不一致，触发告警和补偿

补偿逻辑：
if (订单状态=PAID && 支付单状态!=SUCCESS) {
  // 订单已支付但支付单未成功，可能是支付服务更新失败
  重试更新支付单状态
} else if (订单状态!=PAID && 支付单状态=SUCCESS) {
  // 支付成功但订单未更新，可能是订单服务更新失败
  重试更新订单状态
}
```

优点：
- 及时发现问题
- 用户感知小

缺点：
- 增加延迟
- 对账服务成为瓶颈

适用场景：
- 核心流程（支付、扣款）
- 对一致性要求极高的场景

**方案二：定时对账**

核心思想：
定时（如每小时、每天）对账，批量发现和修复问题。

设计：
```text
对账任务（每小时执行）：
1. 查询最近1小时的订单：
   SELECT * FROM orders
   WHERE created_at >= NOW() - INTERVAL 1 HOUR

2. 对每个订单进行对账：
   - 查询订单信息（order）
   - 查询库存记录（inventory_log）
   - 查询支付记录（payment）
   - 查询物流记录（logistics）

3. 检查一致性：
   订单状态 vs 支付状态
   订单金额 vs 支付金额
   订单库存扣减 vs 库存日志

4. 发现不一致：
   - 记录到对账差异表
   - 触发告警
   - 尝试自动补偿
```

对账差异表：
```sql
CREATE TABLE reconciliation_diff (
  id BIGINT PRIMARY KEY,
  order_id VARCHAR(64),
  diff_type VARCHAR(50),  -- PAYMENT_MISMATCH/INVENTORY_MISMATCH
  expected_value VARCHAR(200),
  actual_value VARCHAR(200),
  status VARCHAR(20),     -- PENDING/COMPENSATED/MANUAL
  created_at TIMESTAMP,
  compensated_at TIMESTAMP
);
```

优点：
- 批量处理，效率高
- 不影响业务性能
- 可以发现各种不一致

缺点：
- 延迟高（小时级）
- 用户可能已感知问题

适用场景：
- 非核心流程
- 对实时性要求不高的场景
- 大批量数据对账

**方案三：事件溯源+状态重建**

核心思想：
记录所有事件，通过重放事件重建状态，与当前状态对比。

设计：
```text
事件表：
CREATE TABLE domain_events (
  event_id VARCHAR(64) PRIMARY KEY,
  aggregate_id VARCHAR(64),  -- orderId
  event_type VARCHAR(50),    -- OrderCreated/OrderPaid
  payload JSON,
  version INT,
  created_at TIMESTAMP
);

对账逻辑：
1. 查询订单的所有事件：
   SELECT * FROM domain_events
   WHERE aggregate_id='order123'
   ORDER BY version

2. 重放事件，重建订单状态：
   Order order = new Order();
   for (event in events) {
     order.apply(event);  // OrderCreated → OrderPaid → OrderShipped
   }

3. 对比重建状态 vs 数据库状态：
   rebuiltOrder.status vs dbOrder.status
   rebuiltOrder.amount vs dbOrder.amount

4. 如果不一致，说明有事件丢失或数据被错误修改
```

优点：
- 可追溯完整历史
- 可精确定位问题
- 天然支持审计

缺点：
- 事件存储成本高
- 重建状态复杂
- 实施难度大

适用场景：
- 金融系统
- 审计要求高的场景

**方案对比**：

| 方案 | 实时性 | 准确性 | 成本 | 复杂度 | 适用场景 |
|------|--------|--------|------|--------|----------|
| 实时对账 | ★★★★★ | ★★★☆☆ | ★★★☆☆ | ★★★★☆ | 核心流程 |
| 定时对账 | ★★☆☆☆ | ★★★★★ | ★★★★☆ | ★★★☆☆ | 一般流程 |
| 事件溯源 | ★★★☆☆ | ★★★★★ | ★★☆☆☆ | ★★☆☆☆ | 金融系统 |

**推荐方案**：
对于电商系统，推荐**定时对账为主，实时对账为辅**。

实施要点：

1. **对账维度设计**：
   ```
   维度1：订单-支付对账
   - 订单状态=PAID ⇔ 存在成功的支付记录
   - 订单金额 = 支付金额

   维度2：订单-库存对账
   - 订单商品 ⇔ 库存扣减记录
   - 订单数量 = 库存扣减数量

   维度3：订单-物流对账
   - 订单状态=SHIPPED ⇔ 存在物流单

   维度4：财务对账
   - 订单收入 = 支付收入 - 退款
   ```

2. **补偿策略**：
   ```
   自动补偿（低风险）：
   - 订单已支付，库存未扣减 → 自动扣减库存
   - 订单已取消，库存未释放 → 自动释放库存

   人工介入（高风险）：
   - 订单金额与支付金额不一致 → 人工审核
   - 库存为负数 → 人工调整
   - 重复支付 → 人工退款
   ```

3. **对账任务调度**：
   ```
   实时对账：
   - 支付成功后：立即对账订单-支付

   分钟级对账：
   - 每5分钟：对账最近10分钟的订单

   小时级对账：
   - 每小时：对账最近2小时的订单

   日级对账：
   - 每天凌晨：对账前一天所有订单
   - 生成对账报表
   ```

4. **补偿幂等性**：
   ```
   补偿操作必须幂等：
   - 记录补偿历史（避免重复补偿）
   - 使用业务唯一键
   - 状态机保证（只能从错误状态补偿到正确状态）
   ```

5. **监控告警**：
   ```
   指标：
   - 对账差异数量
   - 自动补偿成功率
   - 人工处理待办数量

   告警：
   - 差异数量超过阈值
   - 自动补偿失败
   - 关键差异（金额不一致）
   ```

**延伸思考**：
1. 如果对账也失败了（如查询超时），如何处理？
2. 补偿操作失败后如何处理？
3. 如何设计对账结果的可视化展示？

---

##### 递进追问

- 哪些步骤必须同步确认，哪些步骤可以通过事件最终一致？
- 在重试、并发和下游不可用时，如何保证状态可恢复、可追踪？
- 规模扩大十倍后，热点、容量、隔离和降级策略如何变化？

##### 常见失分点

- 混淆领域事实、派生读模型和流程状态。
- 只描述成功路径，遗漏幂等、对账、补偿或人工处理入口。
- 把缓存、消息队列或搜索索引错误地当作交易权威来源。


#### 60. 如何处理分布式系统的时钟问题？

##### 题干与约束

在分布式系统中，不同服务器的时钟可能不同步，导致时间戳不一致、时序错误等问题。如何处理分布式系统的时钟问题？

##### 答案骨架


**问题描述**：
在分布式系统中，不同服务器的时钟可能不同步，导致时间戳不一致、时序错误等问题。如何处理分布式系统的时钟问题？

**答案**：

**问题分析**：
分布式时钟的核心挑战：
1. 时钟漂移：不同机器时钟不一致
2. 时序依赖：如何判断事件先后顺序
3. 超时判断：如何准确计算超时
4. 数据时效：如何判断数据是否过期

**方案一：使用NTP时钟同步**

核心思想：
通过NTP协议同步所有服务器的时钟。

实现：
```text
1. 配置NTP服务器：
   所有应用服务器配置相同的NTP源

2. 定期同步：
   ntpd守护进程自动同步时钟

3. 监控时钟偏移：
   监控各服务器与NTP服务器的时钟差
   差异超过100ms告警
```

优点：
- 实施简单
- 对应用透明
- 时钟基本一致

缺点：
- 无法完全同步（仍有毫秒级误差）
- 时钟回拨问题（同步时时钟可能后退）
- 依赖网络

适用场景：
- 对时间精度要求不高的场景
- 作为基础设施

**方案二：逻辑时钟（Lamport时钟）**

核心思想：
不依赖物理时钟，用逻辑计数器表示事件顺序。

实现：
```text
每个节点维护一个计数器：
1. 节点发生事件时，计数器+1
2. 节点发送消息时，附带当前计数器值
3. 节点收到消息时，更新计数器：
   counter = max(local_counter, message_counter) + 1

示例：
节点A: counter=5, 发送消息(counter=5)
节点B: 收到消息, local_counter=3
        更新counter = max(3, 5) + 1 = 6
```

优点：
- 不依赖物理时钟
- 可以判断因果关系
- 实现简单

缺点：
- 只能判断偏序（不能判断所有事件的先后）
- 不是真实时间
- 计数器可能很大

适用场景：
- 分布式日志
- 事件顺序
- 因果一致性

**方案三：混合逻辑时钟（HLC）**

核心思想：
结合物理时钟和逻辑时钟，既有真实时间又有顺序保证。

实现：
```text
HLC = (physicalTime, logicalCounter)

更新规则：
1. 本地事件：
   pt = 物理时钟
   if (pt > hlc.pt) {
     hlc = (pt, 0)
   } else {
     hlc = (hlc.pt, hlc.lc + 1)
   }

2. 收到消息(msg_hlc)：
   pt = max(物理时钟, msg_hlc.pt, hlc.pt)
   if (pt > hlc.pt) {
     hlc = (pt, 0)
   } else if (pt == msg_hlc.pt) {
     hlc = (pt, max(hlc.lc, msg_hlc.lc) + 1)
   } else {
     hlc = (hlc.pt, hlc.lc + 1)
   }

示例：
节点A: HLC=(100, 0), 发生事件
       物理时钟=99 < 100
       HLC=(100, 1)

节点B: 收到消息HLC=(100, 1)
       物理时钟=105
       HLC=(105, 0)
```

优点：
- 有真实时间（可展示给用户）
- 有顺序保证（逻辑计数器）
- 时钟单调递增（不会回退）

缺点：
- 实现复杂
- 需要所有节点支持

适用场景：
- 分布式数据库（CockroachDB使用）
- 需要时间戳又要顺序的场景

**方案对比**：

| 方案 | 时间准确性 | 顺序保证 | 实施难度 | 适用场景 |
|------|-----------|---------|---------|----------|
| NTP同步 | ★★★★☆ | ★★☆☆☆ | ★★★★★ | 通用 |
| Lamport时钟 | ★☆☆☆☆ | ★★★★★ | ★★★★☆ | 事件顺序 |
| 混合逻辑时钟 | ★★★★☆ | ★★★★★ | ★★★☆☆ | 分布式DB |

**推荐方案**：
对于电商系统，推荐**NTP同步 + 避免依赖绝对时间**。

实施要点：

1. **NTP基础设施**：
   ```
   - 部署内网NTP服务器
   - 所有应用服务器同步内网NTP
   - 监控时钟偏移（超过100ms告警）
   - 禁止手动修改系统时间
   ```

2. **避免依赖绝对时间**：
   ```
   错误示例：
   // 判断订单是否超时（依赖绝对时间）
   if (now() - order.createdAt > 30分钟) {
     cancelOrder()
   }
   问题：如果时钟回拨，可能误判

   正确示例：
   // 使用相对时间或逻辑状态
   if (order.status == PENDING && order.createdAt < now() - 30分钟) {
     // 且使用定时任务扫描（而非实时判断）
     cancelOrder()
   }
   ```

3. **处理时钟回拨**：
   ```
   生成ID时（如雪花ID）：
   if (currentTime < lastTime) {
     // 时钟回拨，等待追上
     wait(lastTime - currentTime)
   }

   或使用单调递增ID：
   // 不依赖时间，只保证递增
   nextId = atomicIncrement()
   ```

4. **使用逻辑版本号**：
   ```
   数据表：
   CREATE TABLE orders (
     order_id VARCHAR(64),
     version INT,  -- 逻辑版本号（不依赖时间）
     updated_at TIMESTAMP
   );

   更新时：
   UPDATE orders
   SET version=version+1, updated_at=NOW()
   WHERE order_id=? AND version=?
   ```

5. **时间窗口设计**：
   ```
   对账任务：
   // 不对账"最近5分钟"的数据（避免时钟误差）
   SELECT * FROM orders
   WHERE created_at < NOW() - INTERVAL 5 MINUTE
     AND created_at >= NOW() - INTERVAL 1 HOUR
   ```

**延伸思考**：
1. 如何设计分布式系统的全局唯一ID（考虑时钟回拨）？
2. 如何在不同时区的数据中心部署系统？
3. 时钟跳跃（突然快进）如何处理？

---

##### 递进追问

- 哪些步骤必须同步确认，哪些步骤可以通过事件最终一致？
- 在重试、并发和下游不可用时，如何保证状态可恢复、可追踪？
- 规模扩大十倍后，热点、容量、隔离和降级策略如何变化？

##### 常见失分点

- 混淆领域事实、派生读模型和流程状态。
- 只描述成功路径，遗漏幂等、对账、补偿或人工处理入口。
- 把缓存、消息队列或搜索索引错误地当作交易权威来源。


#### 61. 强一致性和最终一致性分别适合哪些业务？

追问：订单、评论数、搜索索引分别怎么选，为什么？


#### 62. Snowflake ID 是否可以同时满足订单号的全部要求？

**题型：** 快问快答，5 分钟
**预期结论：** Snowflake 可提供高吞吐、趋势有序的内部 ID，但通常不能单独满足防枚举、外部展示、路由和审计需求。
**适用边界：** 时钟回拨、机器 ID 分配和序列溢出需要明确运行策略；面向用户的订单号可与内部主键分离。


#### 63. 数据迁移、双写切换与最终一致性

##### 题干与约束
设计一个可回滚的数据迁移方案，要求新旧系统在迁移期间持续服务，并能发现和修复差异。

##### 答案骨架
1. 先定义字段映射、数据范围、权威写入方、差异容忍度和迁移窗口。
2. 复制历史快照后持续捕获增量变更；为每条记录保留版本、迁移批次和来源标识。
3. 影子读比对新旧结果，按租户或分片灰度切换读流量。
4. 写入阶段避免无边界双写；需要双写时记录两侧结果，异步对账并设置切回旧系统的截止点。
5. 迁移完成后冻结旧写入口，复核总量、关键字段、聚合指标和抽样业务链路，再进入只读观察期。

##### 关键决策
- 每阶段都要有明确的成功阈值、暂停条件和回滚动作。
- 把差异修复做成可追踪任务，不以“最终一致”掩盖未完成的数据修复。

##### 故障与追问
增量延迟持续升高或关键金额字段不一致时，停止扩大流量；回到旧权威源，保留增量日志，完成补偿与复核后再继续切换。


#### 64. 40 亿数据去重

##### 题干与约束
在内存受限的条件下，对数十亿条记录进行去重并说明准确性与资源取舍。

##### 答案骨架
**方案对比**：

| 方案 | 空间 | 精确度 | 支持删除 |
|------|------|--------|----------|
| **Bitmap** | 40亿 ≈ 512MB | 精确 | 否 |
| **Bloom Filter** | 极小（几十 MB） | 有误判 | 否（Counting BF 可以，但空间 ×4） |
| **HyperLogLog** | 12KB | 误差 0.81% | 否 |

**最佳回答**：
- 40亿 QQ 号（unsigned int 范围 0~2^32）→ **Bitmap**，约 512MB 可精确去重。
- 若内存更紧张或允许少量误判 → **Bloom Filter**。
- 只需统计基数（不需要知道具体哪些重复）→ **HyperLogLog**。

---


#### 65. 实时排行榜

##### 题干与约束
设计一个支持实时更新、查询和分页的海量用户排行榜。

##### 答案骨架
**Redis ZSet 方案**：

```redis
ZADD rank 5000 "player_1"
ZREVRANGE rank 0 9  -- Top 10
ZRANK rank "player_1" -- 查排名
```

**陷阱**：ZSet 元素超过千万级 → 大 Key 阻塞主线程。

**解决方案（分桶 + 聚合）**：
1. 按玩家 ID 模 N 分到 N 个 ZSet：`rank_0, rank_1 ... rank_N`。
2. 每个桶取 Top K。
3. 应用层归并 N 个桶的 Top K，得到全局 Top K。

**分页优化**：
- `ZRANGE` 深分页性能差（O(logN + M)）。
- **游标分页**：记录上一页最后的 `(score, member_id)`，下一页从该位置继续查。
- **快照分页**：定时 dump 排行到 DB，前端查快照。

---


#### 66. 海量数据排序

##### 题干与约束
在内存小于数据集的情况下，对海量数据进行稳定、可恢复的排序。

##### 答案骨架
1. **分块读入**：每次读入 8GB → 内存快排 → 写出有序文件。
2. **多路归并**：用小顶堆同时从 13 个有序文件中取最小值，输出全局有序文件。
3. **分布式**：MapReduce / Spark 分布式排序。

---


#### 67. 10 亿用户在线状态

##### 题干与约束
设计一个可查询海量用户在线状态并控制存储与更新成本的系统。

##### 答案骨架
**Bitmap**：1 bit 表示 1 个用户的在线/离线。1亿用户仅 12MB，10 亿用户约 120MB。

```redis
SETBIT online 123456 1   -- 用户123456上线
GETBIT online 123456     -- 查询是否在线
BITCOUNT online          -- 统计在线人数
```

---

### 三、典型业务场景设计


## 5. 中间件、存储与异步处理

#### 68. 检索场景为什么不总是使用 Elasticsearch？

##### 题干与约束
需要解释复杂搜索与按主键、简单条件查询的不同技术选择。
##### 答案骨架
主键和有限条件查询通常由事务存储和索引满足；全文检索、多字段筛选、相关性排序、聚合和复杂分页更适合作为独立搜索读模型。引入 Elasticsearch 后要接受索引延迟，设计重建、异步同步、版本控制和回退查询。
##### 递进追问
搜索索引落后于商品主数据时，详情页和交易创建分别以什么数据为准？
##### 常见失分点
把 Elasticsearch 当权威事务库；只谈性能；忽略运维和索引重建成本。


#### 69. 何时选择 Elasticsearch 而不是 MySQL？

##### 题干与约束
商品需要关键词搜索、筛选、排序和聚合，同时交易系统不能依赖搜索索引正确性。
##### 答案骨架
当业务需要全文检索、多维筛选、相关性排序、聚合或深分页治理时选择 Elasticsearch；简单查询继续使用 MySQL。主数据变更通过异步事件更新索引，索引按版本幂等，支持全量重建和补偿；交易创建始终以权威商品、库存和价格校验为准。
##### 递进追问
索引更新延迟时，搜索结果中的过期商品怎样处理？
##### 常见失分点
所有查询上搜索系统；同步写主库和索引；让订单直接信任索引字段。


#### 70. 搜索性能优化

##### 题干与约束

搜索响应时间P99达到2秒，用户体验差。如何优化搜索性能到100ms以内？

##### 答案骨架


**问题描述**：
搜索响应时间P99达到2秒，用户体验差。如何优化搜索性能到100ms以内？

**答案**：

**问题分析**：
搜索慢的常见原因：
1. ES查询复杂（深度分页、大量聚合）
2. 索引设计不合理
3. 数据量大
4. 网络延迟

**优化方案**：

1. **查询优化**：
   ```
   避免深度分页：
   ❌ from=10000, size=20（跳过1万条数据）
   ✅ search_after（游标分页）

   减少聚合计算：
   ❌ 聚合100个字段
   ✅ 聚合最常用的10个字段

   字段裁剪：
   ❌ 返回所有字段
   ✅ _source: ["id", "title", "price"]
   ```

2. **缓存策略**：
   ```
   热门搜索缓存：
   key: search:q=iPhone&page=1
   value: {商品列表}
   TTL: 5分钟

   命中率：70%+
   ```

3. **索引优化**：
   ```
   分片数量：
   - 单分片大小：20-50GB
   - 过多分片影响性能

   副本数量：
   - 副本数=2（高可用+读负载均衡）

   Segment合并：
   - 定期force_merge减少segment数量
   ```

**延伸思考**：
1. 如何设计搜索的降级方案（ES故障）？
2. 搜索性能如何监控和告警？

---

##### 递进追问

- 哪些步骤必须同步确认，哪些步骤可以通过事件最终一致？
- 在重试、并发和下游不可用时，如何保证状态可恢复、可追踪？
- 规模扩大十倍后，热点、容量、隔离和降级策略如何变化？

##### 常见失分点

- 混淆领域事实、派生读模型和流程状态。
- 只描述成功路径，遗漏幂等、对账、补偿或人工处理入口。
- 把缓存、消息队列或搜索索引错误地当作交易权威来源。


#### 71. 智能搜索（NLP+AI）

##### 题干与约束

用户搜索"适合送女朋友的礼物"，如何理解用户意图，推荐合适商品？

##### 答案骨架


**问题描述**：
用户搜索"适合送女朋友的礼物"，如何理解用户意图，推荐合适商品？

**答案**：

**问题分析**：
传统搜索只能匹配关键词，无法理解语义。

**解决方案**：

1. **意图识别**：
   ```
   NLP分析：
   "适合送女朋友的礼物"
   → 意图：礼物推荐
   → 对象：女性
   → 场景：送礼

   映射到类目：
   - 珠宝首饰
   - 化妆品
   - 鲜花
   ```

2. **语义搜索**：
   ```
   使用BERT等模型：
   - 将搜索词编码为向量
   - 商品标题也编码为向量
   - 计算向量相似度
   - 按相似度排序
   ```

**延伸思考**：
1. 如何训练电商领域的语义模型？
2. 语义搜索如何与传统搜索结合？

---

##### 递进追问

- 哪些步骤必须同步确认，哪些步骤可以通过事件最终一致？
- 在重试、并发和下游不可用时，如何保证状态可恢复、可追踪？
- 规模扩大十倍后，热点、容量、隔离和降级策略如何变化？

##### 常见失分点

- 混淆领域事实、派生读模型和流程状态。
- 只描述成功路径，遗漏幂等、对账、补偿或人工处理入口。
- 把缓存、消息队列或搜索索引错误地当作交易权威来源。


#### 72. 搜索结果的多样性优化

##### 题干与约束

用户搜索"手机"，前10个结果都是iPhone，缺乏多样性。如何优化搜索结果的多样性？

##### 答案骨架


**问题描述**：
用户搜索"手机"，前10个结果都是iPhone，缺乏多样性。如何优化搜索结果的多样性？

**答案**：

**问题分析**：
多样性不足的问题：
1. 马太效应（热门商品更热门）
2. 用户需求多样，不都想要iPhone
3. 影响长尾商品曝光

**优化方案**：

1. **品牌打散**：
   ```
   规则：前10个结果中，同一品牌最多出现3次

   算法：
   1. 按相关性排序
   2. 遍历结果，统计品牌出现次数
   3. 如果某品牌超过阈值，跳过该商品，选下一个
   ```

2. **MMR算法（最大边际相关性）**：
   ```
   score = λ × relevance - (1-λ) × max_similarity

   relevance: 与查询的相关性
   max_similarity: 与已选结果的最大相似度
   λ: 权衡参数（0.7）

   每次选择score最高的商品，保证相关性和多样性
   ```

3. **类目多样性**：
   ```
   前10个结果覆盖2-3个子类目
   - 智能手机（5个）
   - 老人机（3个）
   - 游戏手机（2个）
   ```

**延伸思考**：
1. 多样性和相关性如何权衡？
2. 如何评估搜索结果的多样性？

---

---

##### 递进追问

- 哪些步骤必须同步确认，哪些步骤可以通过事件最终一致？
- 在重试、并发和下游不可用时，如何保证状态可恢复、可追踪？
- 规模扩大十倍后，热点、容量、隔离和降级策略如何变化？

##### 常见失分点

- 混淆领域事实、派生读模型和流程状态。
- 只描述成功路径，遗漏幂等、对账、补偿或人工处理入口。
- 把缓存、消息队列或搜索索引错误地当作交易权威来源。


#### 73. 什么场景应该引入消息队列？

##### 题干与约束
订单成功后需要通知、积分和索引更新，但主链路不能被非核心下游拖慢。
##### 答案骨架
消息队列适合削峰、异步解耦、事件传播和失败重试，不是“解耦”万能答案。核心状态先在本地事务内落稳，通过本地消息表或可靠事件发布异步驱动下游；按业务键设计分区顺序，消费者幂等，积压时限流、扩容、回压或降级。
##### 递进追问
订单创建成功但事件未发出，怎样避免下游长期遗漏？
##### 常见失分点
事务内同步发送消息且无补偿；以为消息顺序等于业务正确；忽略积压和死信。


#### 74. 如何降低 Kafka 消息丢失风险？

##### 题干与约束
关键事件需从生产端到消费端降低丢失风险，并能被业务恢复。
##### 答案骨架
生产端使用确认、重试和幂等生产者；集群端使用副本和同步副本集合；消费者在业务处理成功后再提交位点。端到端仍需要本地消息表或可重放事件、幂等消费、监控积压和补偿，因为消息系统配置不能证明业务副作用已经完成。
##### 递进追问
数据库事务已提交但生产者宕机，怎样确保事件最终发出？
##### 常见失分点
只配置确认；先提交位点；把生产者幂等误当业务幂等。


#### 75. 消息重复时如何保证结果正确？

##### 题干与约束
消费者按至少一次投递接收事件，重复消费不能造成重复扣款、积分或状态回退。
##### 答案骨架
默认假设消息会重复。消费者以业务唯一键或事件标识建立去重记录，结合数据库唯一约束、状态机条件更新或幂等写入，使重复执行得到相同结果。处理与标记完成要可恢复，失败可安全重试；生产者幂等只减少投递重复，不能替代业务幂等。
##### 递进追问
消费者已产生外部副作用但进程在标记完成前崩溃，如何恢复？
##### 常见失分点
仅依赖消息 ID 的内存去重；没有持久化约束；混淆投递幂等和业务幂等。


#### 76. 如何设计配置中心？

##### 题干与约束

微服务架构下，配置分散在各个服务中，修改配置需要重启服务。请设计一个配置中心，支持配置的集中管理和动态更新。

##### 答案骨架


**问题描述**：
微服务架构下，配置分散在各个服务中，修改配置需要重启服务。请设计一个配置中心，支持配置的集中管理和动态更新。

**答案**：

**问题分析**：
配置中心的核心挑战：
1. 配置变更如何实时推送到服务
2. 如何保证配置的一致性和可靠性
3. 如何支持灰度发布和快速回滚
4. 如何保证配置的安全性（敏感信息加密）

**方案一：基于文件+定时拉取**

核心思路：
配置存储在Git，服务定时拉取配置文件。

设计：
- **存储**：配置文件存储在Git仓库
- **拉取**：服务每隔30秒拉取一次配置
- **生效**：检测到配置变更，重新加载
- **版本**：Git commit作为配置版本

优点：
- 实现简单
- 天然的版本管理
- 可以code review配置

缺点：
- 实时性差（最多30秒延迟）
- Git作为配置中心不太合适
- 无法精准推送

**方案二：基于数据库+长轮询**

核心思路：
配置存储在数据库，服务通过长轮询获取配置更新。

设计：
- **存储**：配置存储在MySQL，包含版本号
- **推送**：服务发起长轮询请求（超时60秒）
- **变更检测**：配置中心检测到配置变更，立即返回
- **生效**：服务收到变更通知，重新加载配置

优点：
- 实时性好（秒级）
- 实现相对简单
- 支持灰度发布

缺点：
- 长连接占用资源
- 数据库压力大（大量服务轮询）
- 扩展性有限

**方案三：基于注册中心+Watch机制**

核心思路：
配置存储在注册中心（如Nacos、Apollo），通过Watch机制推送。

设计：
- **存储**：配置存储在Nacos
- **Watch**：服务订阅配置，Nacos主动推送变更
- **命名空间**：按环境（dev/test/prod）隔离
- **灰度发布**：支持按IP、比例灰度
- **权限控制**：RBAC权限管理

实现：
```text
1. 服务启动时注册到Nacos
2. 订阅所需的配置（dataId + group）
3. Nacos检测到配置变更，通过长连接推送
4. 服务收到通知，触发配置刷新回调
```

优点：
- 实时性强（毫秒级）
- 功能完善（灰度、回滚、审计）
- 高可用（Nacos集群）
- 开箱即用

缺点：
- 依赖第三方组件
- 学习成本
- 运维复杂度

**方案对比**：

| 维度 | 文件+拉取 | 数据库+长轮询 | 注册中心+Watch |
|------|-----------|--------------|---------------|
| 实时性 | ★★☆☆☆ | ★★★★☆ | ★★★★★ |
| 可靠性 | ★★★☆☆ | ★★★☆☆ | ★★★★★ |
| 扩展性 | ★★★☆☆ | ★★☆☆☆ | ★★★★★ |
| 实施成本 | ★★★★★ | ★★★★☆ | ★★★☆☆ |

**推荐方案**：
对于中大型系统，推荐**使用Nacos作为配置中心**。

实施要点：
1. **配置分层**：
   - 环境配置（dev/test/prod）
   - 公共配置（数据库连接池、日志级别）
   - 应用配置（业务参数）
   - 敏感配置（密码、密钥）加密存储

2. **命名规范**：
   - dataId：`${应用名}-${环境}.${格式}`
   - group：`${业务域}`
   - 例：`order-service-prod.yaml`，group：`transaction`

3. **配置刷新**：
   - 使用 `@RefreshScope` 注解
   - 或实现 `ConfigChangeListener` 接口
   - 敏感配置（数据库连接）不支持热更新

4. **灰度发布**：
   - 先在灰度环境验证
   - 按IP或比例逐步推送
   - 监控关键指标，出问题立即回滚

5. **安全控制**：
   - 敏感配置加密存储（AES/RSA）
   - RBAC权限管理（谁能改什么配置）
   - 审计日志（谁在什么时候改了什么）
   - 配置变更必须经过审批流程

6. **高可用**：
   - Nacos集群部署（至少3节点）
   - 客户端本地缓存（Nacos不可用时降级）
   - 配置备份（定期导出到Git）

**延伸思考**：
1. 配置中心本身如何保证高可用？
2. 敏感配置如何加密存储？
3. 如何保证配置变更的安全性（防止误操作）？

---

##### 递进追问

- 哪些步骤必须同步确认，哪些步骤可以通过事件最终一致？
- 在重试、并发和下游不可用时，如何保证状态可恢复、可追踪？
- 规模扩大十倍后，热点、容量、隔离和降级策略如何变化？

##### 常见失分点

- 混淆领域事实、派生读模型和流程状态。
- 只描述成功路径，遗漏幂等、对账、补偿或人工处理入口。
- 把缓存、消息队列或搜索索引错误地当作交易权威来源。


#### 77. 如何选择同步调用vs异步消息？

##### 题干与约束

在微服务架构中，服务间通信可以使用同步RPC或异步消息队列。在电商系统中，如何选择合适的通信方式？

##### 答案骨架


**问题描述**：
在微服务架构中，服务间通信可以使用同步RPC或异步消息队列。在电商系统中，如何选择合适的通信方式？

**答案**：

**问题分析**：
同步vs异步的核心考量：
1. 业务语义：是否需要立即返回结果
2. 性能要求：延迟vs吞吐量
3. 可靠性：是否允许消息丢失
4. 复杂度：实现和运维成本

**方案一：全部使用同步RPC**

适用场景：
- 查询操作（查询订单详情、商品信息）
- 强实时性要求（下单时检查库存）
- 需要立即返回结果（用户等待响应）

优点：
- 实现简单
- 调用链路清晰
- 易于调试

缺点：
- 性能瓶颈（串行调用）
- 可用性差（下游故障影响上游）
- 难以削峰

**方案二：全部使用异步消息**

适用场景：
- 通知类操作（发送短信、邮件）
- 可延迟处理（数据同步、报表生成）
- 需要削峰填谷（秒杀、大促）

优点：
- 解耦（服务独立）
- 削峰（消息堆积）
- 高吞吐

缺点：
- 最终一致性
- 消息丢失风险
- 调试困难

**方案三：混合使用（推荐）**

决策矩阵：

| 场景 | 通信方式 | 理由 |
|------|---------|------|
| 查询商品详情 | 同步RPC | 需要立即返回 |
| 下单扣减库存 | 同步RPC | 需要立即知道结果 |
| 订单支付成功→通知物流 | 异步消息 | 不需要立即处理 |
| 订单支付成功→发送短信 | 异步消息 | 允许延迟 |
| 商品信息变更→更新搜索 | 异步消息 | 最终一致即可 |
| 计算订单金额 | 同步RPC | 需要立即返回金额 |
| 订单创建→更新统计报表 | 异步消息 | 非实时 |

决策原则：
1. **用户在等待**：使用同步（如下单、支付、查询）
2. **用户不在等待**：使用异步（如通知、数据同步）
3. **强一致性**：使用同步（如扣款、扣库存）
4. **最终一致性**：使用异步（如积分、优惠券）
5. **高并发**：优先异步（如秒杀、大促）

优点：
- 平衡性能和一致性
- 灵活应对不同场景
- 整体架构合理

缺点：
- 需要维护两套通信机制
- 团队需要理解选择原则

**方案对比**：

| 维度 | 全同步 | 全异步 | 混合 |
|------|--------|--------|------|
| 实时性 | ★★★★★ | ★★☆☆☆ | ★★★★☆ |
| 吞吐量 | ★★☆☆☆ | ★★★★★ | ★★★★☆ |
| 可用性 | ★★☆☆☆ | ★★★★★ | ★★★★☆ |
| 复杂度 | ★★★★☆ | ★★☆☆☆ | ★★★☆☆ |

**推荐方案**：
采用**混合模式**，根据场景选择合适的通信方式。

实施要点：
1. **同步调用优化**：
   - 设置合理超时（如3秒）
   - 使用断路器防止雪崩
   - 重要接口设置重试机制
   - 监控调用成功率和延迟

2. **异步消息优化**：
   - 使用本地消息表保证可靠性
   - 消费端幂等处理
   - 死信队列处理失败消息
   - 监控消息积压和消费延迟

3. **场景识别技巧**：
   - 问：用户是否在等待结果？
   - 问：失败了是否需要立即知道？
   - 问：是否需要强一致性？
   - 问：并发量有多大？

4. **混合调用模式**：
   ```
   示例：订单支付成功后

   同步：
   - 更新订单状态（用户需要立即看到）
   - 扣减库存（强一致性）

   异步：
   - 通知物流（可延迟）
   - 发送短信（可延迟）
   - 更新报表（可延迟）
   - 赠送积分（最终一致）
   ```

5. **降级策略**：
   - 异步消息：队列满时拒绝接入
   - 同步调用：超时降级（返回默认值或缓存）

**延伸思考**：
1. 如何处理异步消息丢失的情况？
2. 同步调用超时后如何判断是否成功？
3. 如何在同步和异步之间切换（如异步改同步）？

---

##### 递进追问

- 哪些步骤必须同步确认，哪些步骤可以通过事件最终一致？
- 在重试、并发和下游不可用时，如何保证状态可恢复、可追踪？
- 规模扩大十倍后，热点、容量、隔离和降级策略如何变化？

##### 常见失分点

- 混淆领域事实、派生读模型和流程状态。
- 只描述成功路径，遗漏幂等、对账、补偿或人工处理入口。
- 把缓存、消息队列或搜索索引错误地当作交易权威来源。


#### 78. 设计事件驱动架构

##### 题干与约束

电商系统需要实现事件驱动架构，当订单状态变更时，自动触发物流、消息通知、数据统计等下游操作。请设计事件驱动方案。

##### 答案骨架


**问题描述**：
电商系统需要实现事件驱动架构，当订单状态变更时，自动触发物流、消息通知、数据统计等下游操作。请设计事件驱动方案。

**答案**：

**问题分析**：
事件驱动架构的核心挑战：
1. 如何设计领域事件
2. 如何保证事件不丢失
3. 如何处理事件顺序性
4. 如何避免事件风暴

**方案一：基于数据库Change Data Capture（CDC）**

核心思想：
监听数据库变更日志（binlog），自动生成事件。

设计：
```text
MySQL binlog → Debezium → Kafka → 下游服务

示例：
orders表INSERT → Debezium捕获 →
  发送到Kafka主题: order.events →
  物流服务消费 → 创建运单
```

优点：
- 零侵入（不需要改业务代码）
- 事件不丢失（基于binlog）
- 实时性高

缺点：
- 事件语义不清晰（只有数据变更）
- 难以表达业务意图
- 依赖数据库

适用场景：
- 数据同步
- 数据库归档
- 实时数仓

**方案二：基于领域事件+Outbox模式**

核心思想：
业务代码显式发布领域事件，通过Outbox模式保证可靠性。

设计：
```text
1. 订单服务发布事件：
   BEGIN TRANSACTION
     UPDATE orders SET status='PAID'
     INSERT INTO outbox_events (
       event_id, event_type, payload, status
     ) VALUES (
       UUID(), 'OrderPaid', '{"orderId":"123"}', 'PENDING'
     )
   COMMIT

2. 事件发布器（独立进程）：
   while (true) {
     events = SELECT * FROM outbox_events WHERE status='PENDING' LIMIT 100
     for (event in events) {
       kafka.send(event.event_type, event.payload)
       UPDATE outbox_events SET status='SENT' WHERE event_id=event.id
     }
     sleep(1s)
   }

3. 下游服务消费：
   物流服务监听order.paid主题
   消息服务监听order.paid主题
   报表服务监听order.paid主题
```

领域事件设计：
```text
OrderCreated {
  orderId, userId, items[], totalAmount, createdAt
}

OrderPaid {
  orderId, paymentId, paidAmount, paidAt
}

OrderShipped {
  orderId, trackingNumber, shippedAt
}

OrderCompleted {
  orderId, completedAt
}
```

优点：
- 业务语义清晰
- 事件可靠性高（Outbox模式）
- 下游解耦

缺点：
- 需要Outbox表和发布器
- 实现复杂度中等

适用场景：
- 微服务间通信
- 业务事件通知
- 事件溯源

**方案三：基于消息队列事务消息**

核心思想：
使用RocketMQ的事务消息，保证事件发送和本地事务一致性。

设计：
```text
1. 发送半消息（Half Message）：
   rocketMQ.sendHalfMessage(topic, "OrderPaid", payload)

2. 执行本地事务：
   BEGIN TRANSACTION
     UPDATE orders SET status='PAID'
   COMMIT

3. 提交/回滚消息：
   if (本地事务成功) {
     rocketMQ.commit(messageId)
   } else {
     rocketMQ.rollback(messageId)
   }

4. 消息回查（如果未收到commit/rollback）：
   rocketMQ定期回查 → 订单服务检查订单状态 → 返回commit/rollback
```

优点：
- 事件可靠性高
- 不需要Outbox表
- RocketMQ原生支持

缺点：
- 依赖特定MQ（RocketMQ）
- 需要实现回查接口

适用场景：
- 使用RocketMQ的系统
- 需要强可靠性的场景

**方案对比**：

| 维度 | CDC | Outbox | 事务消息 |
|------|-----|--------|----------|
| 事件语义 | ★★☆☆☆ | ★★★★★ | ★★★★☆ |
| 可靠性 | ★★★★★ | ★★★★★ | ★★★★★ |
| 侵入性 | ★★★★★ | ★★★☆☆ | ★★★☆☆ |
| 实施难度 | ★★★★☆ | ★★★☆☆ | ★★★★☆ |

**推荐方案**：
对于电商系统，推荐**Outbox模式**。

实施要点：
1. **事件设计原则**：
   - 事件名称：过去时（OrderPaid、OrderShipped）
   - 包含完整上下文（避免下游再查询）
   - 不可变（发出后不能修改）
   - 幂等性（包含event_id）

2. **Outbox表设计**：
   ```sql
   CREATE TABLE outbox_events (
     event_id VARCHAR(64) PRIMARY KEY,
     aggregate_type VARCHAR(50), -- Order/Product
     aggregate_id VARCHAR(64),   -- orderId
     event_type VARCHAR(50),      -- OrderPaid
     payload JSON,                -- 事件数据
     status VARCHAR(20),          -- PENDING/SENT/FAILED
     retry_count INT DEFAULT 0,
     created_at TIMESTAMP,
     sent_at TIMESTAMP
   );
   ```

3. **事件发布器优化**：
   - 批量读取（每次100条）
   - 批量发送（提高吞吐）
   - 失败重试（指数退避）
   - 定期清理已发送事件（保留7天）

4. **消费端幂等**：
   ```
   消费端维护已处理事件表：
   CREATE TABLE processed_events (
     event_id VARCHAR(64) PRIMARY KEY,
     processed_at TIMESTAMP
   );

   处理逻辑：
   1. 检查event_id是否已处理
   2. 如果已处理，直接返回
   3. 执行业务逻辑
   4. 记录event_id到processed_events
   ```

5. **监控告警**：
   - Outbox待发送事件数
   - 事件发送失败率
   - 消费延迟

**延伸思考**：
1. 如何保证事件的顺序性（同一订单的多个事件）？
2. 如何处理事件风暴（大量事件同时发布）？
3. 事件版本如何管理（EventV1、EventV2）？

---

##### 递进追问

- 哪些步骤必须同步确认，哪些步骤可以通过事件最终一致？
- 在重试、并发和下游不可用时，如何保证状态可恢复、可追踪？
- 规模扩大十倍后，热点、容量、隔离和降级策略如何变化？

##### 常见失分点

- 混淆领域事实、派生读模型和流程状态。
- 只描述成功路径，遗漏幂等、对账、补偿或人工处理入口。
- 把缓存、消息队列或搜索索引错误地当作交易权威来源。


#### 79. 如何保证消息的可靠投递？

##### 题干与约束

在消息队列（Kafka/RocketMQ）中，如何保证消息从生产者到消费者的可靠投递，不丢失、不重复、不乱序？

##### 答案骨架


**问题描述**：
在消息队列（Kafka/RocketMQ）中，如何保证消息从生产者到消费者的可靠投递，不丢失、不重复、不乱序？

**答案**：

**问题分析**：
消息可靠性的三个维度：
1. 生产端：如何保证消息发送成功
2. 存储端：如何保证消息不丢失
3. 消费端：如何保证消息处理成功

**方案一：At Least Once（至少一次）**

核心思想：
保证消息至少被消费一次，可能重复但不会丢失。

实现：
```text
生产端：
1. 发送消息到MQ
2. 等待MQ确认（ACK）
3. 如果超时或失败，重试发送

MQ端：
1. 消息写入磁盘后返回ACK
2. 多副本复制（至少2个副本确认）

消费端：
1. 消费消息
2. 处理业务逻辑
3. 手动提交offset
4. 如果处理失败，不提交offset，下次重新消费
```

优点：
- 消息不丢失
- 实现相对简单

缺点：
- 可能重复消费
- 需要业务幂等

适用场景：
- 大部分业务场景
- 可以接受重复的场景

**方案二：At Most Once（至多一次）**

核心思想：
消息可能丢失，但不会重复。

实现：
```text
生产端：
1. 发送消息
2. 不等待确认，直接返回

消费端：
1. 先提交offset
2. 再处理业务逻辑
3. 如果处理失败，消息丢失
```

优点：
- 不会重复
- 性能高

缺点：
- 可能丢消息

适用场景：
- 日志采集
- 监控数据上报
- 允许丢失的场景

**方案三：Exactly Once（精确一次）**

核心思想：
消息既不丢失也不重复，精确消费一次。

实现（基于Kafka事务）：
```text
生产端：
producer.initTransactions()
try {
  producer.beginTransaction()
  producer.send(record1)
  producer.send(record2)
  // 更新本地数据库
  db.update(...)
  producer.commitTransaction()
} catch (Exception e) {
  producer.abortTransaction()
}

消费端：
consumer.subscribe(topic)
consumer.setIsolationLevel(READ_COMMITTED) // 只读已提交
while (true) {
  records = consumer.poll()
  for (record in records) {
    // 幂等处理
    if (isProcessed(record.key)) {
      continue
    }
    process(record)
    markProcessed(record.key)
  }
  consumer.commitSync()
}
```

实现（基于业务幂等）：
```text
消息设计：
{
  "messageId": "uuid",   // 全局唯一ID
  "orderId": "123",
  "payload": {...}
}

消费端：
1. 检查messageId是否已处理（查Redis/DB）
2. 如果已处理，直接返回成功
3. 执行业务逻辑 + 记录messageId（同一事务）
4. 提交offset
```

优点：
- 不丢不重
- 语义最强

缺点：
- 实现复杂
- 性能开销大
- 需要事务支持

适用场景：
- 金融交易
- 支付扣款
- 对准确性要求极高的场景

**方案对比**：

| 语义 | 是否丢失 | 是否重复 | 性能 | 复杂度 | 适用场景 |
|------|---------|---------|------|--------|----------|
| At Least Once | 不丢失 | 可能重复 | ★★★★☆ | ★★★☆☆ | 大部分场景 |
| At Most Once | 可能丢失 | 不重复 | ★★★★★ | ★★★★☆ | 日志、监控 |
| Exactly Once | 不丢失 | 不重复 | ★★☆☆☆ | ★★☆☆☆ | 金融、支付 |

**推荐方案**：
对于电商系统，推荐**At Least Once + 业务幂等**。

实施要点：

1. **生产端可靠性**：
   ```java
   // 同步发送（等待确认）
   producer.send(record).get(3, TimeUnit.SECONDS)

   // 配置
   acks=all              // 所有副本确认
   retries=3            // 重试3次
   max.in.flight.requests.per.connection=1  // 保证顺序
   ```

2. **MQ端可靠性**：
   ```
   Kafka配置：
   - replication.factor=3     // 3副本
   - min.insync.replicas=2    // 至少2个副本确认
   - unclean.leader.election.enable=false  // 禁止非ISR副本成为leader

   RocketMQ配置：
   - flushDiskType=SYNC_FLUSH  // 同步刷盘
   ```

3. **消费端可靠性**：
   ```java
   // 手动提交offset
   while (true) {
     records = consumer.poll()
     try {
       for (record in records) {
         // 幂等处理
         if (!isProcessed(record.messageId)) {
           process(record)
           markProcessed(record.messageId)
         }
       }
       // 处理成功后提交offset
       consumer.commitSync()
     } catch (Exception e) {
       // 处理失败，不提交offset，下次重新消费
       log.error("Process failed", e)
     }
   }
   ```

4. **幂等性设计**：
   ```
   方案1：基于唯一键
   - 消息包含messageId
   - 消费端用messageId去重（Redis/DB）

   方案2：基于业务唯一键
   - 订单号、支付流水号等
   - 数据库唯一索引约束

   方案3：基于版本号
   - 数据包含版本号
   - 更新时检查版本号（乐观锁）
   ```

5. **顺序性保证**：
   ```
   发送端：
   - 同一订单的消息发到同一分区（按orderId hash）
   - max.in.flight.requests=1（保证分区内有序）

   消费端：
   - 单线程消费同一分区
   - 或使用版本号检查顺序
   ```

**延伸思考**：
1. 如果消费失败，消息应该重试几次？
2. 如何处理消息积压问题？
3. 如何实现消息的延迟投递？

---

##### 递进追问

- 哪些步骤必须同步确认，哪些步骤可以通过事件最终一致？
- 在重试、并发和下游不可用时，如何保证状态可恢复、可追踪？
- 规模扩大十倍后，热点、容量、隔离和降级策略如何变化？

##### 常见失分点

- 混淆领域事实、派生读模型和流程状态。
- 只描述成功路径，遗漏幂等、对账、补偿或人工处理入口。
- 把缓存、消息队列或搜索索引错误地当作交易权威来源。


#### 80. 微服务间的版本兼容性设计

##### 题干与约束

微服务架构下，服务A调用服务B的接口。当服务B升级时，如何保证向后兼容，不影响服务A？请设计API版本管理方案。

##### 答案骨架


**问题描述**：
微服务架构下，服务A调用服务B的接口。当服务B升级时，如何保证向后兼容，不影响服务A？请设计API版本管理方案。

**答案**：

**问题分析**：
API版本兼容的核心挑战：
1. 如何在不影响老版本的情况下升级
2. 如何管理多个版本的共存
3. 如何平滑下线老版本
4. 如何处理数据结构变更

**方案一：URL版本控制**

核心思想：
在URL中包含版本号，不同版本独立部署。

实现：
```text
版本1：GET /api/v1/orders/{id}
返回：{
  "orderId": "123",
  "amount": 100.00,
  "status": "PAID"
}

版本2：GET /api/v2/orders/{id}
返回：{
  "orderId": "123",
  "totalAmount": 100.00,    // 字段重命名
  "discountAmount": 10.00,  // 新增字段
  "paymentStatus": "PAID"   // 字段重命名
}

服务端：
@RestController
@RequestMapping("/api/v1")
public class OrderControllerV1 {
  @GetMapping("/orders/{id}")
  public OrderV1 getOrder(@PathVariable String id) {
    return orderService.getOrderV1(id);
  }
}

@RestController
@RequestMapping("/api/v2")
public class OrderControllerV2 {
  @GetMapping("/orders/{id}")
  public OrderV2 getOrder(@PathVariable String id) {
    return orderService.getOrderV2(id);
  }
}
```

优点：
- 版本隔离清晰
- 易于理解
- 支持大版本升级

缺点：
- 需要维护多份代码
- URL变化对客户端不友好
- 版本爆炸

适用场景：
- 大版本升级（API重构）
- 需要长期支持多版本

**方案二：Header版本控制**

核心思想：
URL不变，通过HTTP Header指定版本。

实现：
```text
请求：
GET /api/orders/123
Headers: {
  Accept: application/vnd.company.order.v2+json
}

或：
GET /api/orders/123
Headers: {
  API-Version: 2
}

服务端：
@GetMapping(value = "/orders/{id}",
            produces = "application/vnd.company.order.v1+json")
public OrderV1 getOrderV1(@PathVariable String id) {
  return orderService.getOrderV1(id);
}

@GetMapping(value = "/orders/{id}",
            produces = "application/vnd.company.order.v2+json")
public OrderV2 getOrderV2(@PathVariable String id) {
  return orderService.getOrderV2(id);
}
```

优点：
- URL不变，对客户端友好
- 符合RESTful规范
- 版本信息不污染URL

缺点：
- 调试不方便（Header不可见）
- 浏览器访问不友好
- 实现复杂

适用场景：
- RESTful API
- 对URL稳定性要求高的场景

**方案三：向后兼容设计（推荐）**

核心思想：
不使用显式版本号，通过向后兼容的设计避免版本问题。

兼容原则：
```text
1. 只增不删：
   ✅ 新增字段（老客户端忽略）
   ❌ 删除字段（老客户端会报错）

2. 字段可选：
   ✅ 新字段设为可选
   ❌ 新字段设为必填

3. 默认值：
   ✅ 新字段提供默认值
   ❌ 新字段没有默认值

4. 字段弃用：
   ✅ 保留旧字段，标记为@Deprecated
   ❌ 直接删除旧字段
```

实现示例：
```text
V1版本：
{
  "orderId": "123",
  "amount": 100.00
}

V2版本（向后兼容）：
{
  "orderId": "123",
  "amount": 100.00,          // 保留（兼容V1）
  "totalAmount": 100.00,      // 新增
  "discountAmount": 10.00    // 新增
}

代码：
public class Order {
  private String orderId;

  @Deprecated  // 标记弃用但保留
  private BigDecimal amount;

  private BigDecimal totalAmount;
  private BigDecimal discountAmount;

  // Getter/Setter
  public BigDecimal getAmount() {
    return totalAmount; // 返回新字段值（保证语义一致）
  }
}
```

优点：
- 无需版本管理
- 客户端无需修改
- 平滑升级

缺点：
- 字段累积（历史包袱）
- 无法做破坏性变更
- 需要严格遵守兼容原则

适用场景：
- 微服务间调用
- 小版本迭代
- 高频发布的系统

**方案对比**：

| 方案 | URL稳定性 | 维护成本 | 兼容性 | 适用场景 |
|------|-----------|---------|--------|----------|
| URL版本 | ★★☆☆☆ | ★★☆☆☆ | ★★★★★ | 大版本升级 |
| Header版本 | ★★★★★ | ★★☆☆☆ | ★★★★★ | RESTful API |
| 向后兼容 | ★★★★★ | ★★★★☆ | ★★★★☆ | 微服务 |

**推荐方案**：
对于微服务间调用，推荐**向后兼容设计**。对外API可使用**URL版本控制**。

实施要点：

1. **API设计规范**：
   ```
   必须遵守：
   - 新增字段必须可选
   - 新增字段必须有默认值
   - 不删除现有字段
   - 不修改字段类型
   - 不修改字段语义

   字段弃用流程：
   1. 标记@Deprecated，文档说明
   2. 观察调用量，确认无人使用
   3. 至少保留3个月
   4. 下个大版本时删除
   ```

2. **Protobuf向后兼容**：
   ```protobuf
   message Order {
     string order_id = 1;
     double amount = 2;

     // V2新增字段
     double discount_amount = 3;
     string payment_method = 4;

     // 不要重用字段编号！
     // reserved 5; // 如果删除字段5，标记为reserved
   }
   ```

3. **版本协商机制**：
   ```
   客户端声明支持的版本：
   Headers: {
     X-Client-Version: 2.0
     X-Compatible-Versions: 1.0,1.5,2.0
   }

   服务端根据客户端版本返回合适格式：
   if (clientVersion >= 2.0) {
     return OrderV2(order);
   } else {
     return OrderV1(order); // 降级返回
   }
   ```

4. **版本监控**：
   ```
   监控指标：
   - 各版本API调用量
   - 废弃API的调用量
   - 客户端版本分布

   告警：
   - 废弃API仍有调用
   - 客户端版本过低
   ```

5. **契约测试**：
   ```
   测试用例：
   1. V1客户端调用V2服务（向后兼容）
   2. V2客户端调用V1服务（新字段有默认值）
   3. 并发调用不同版本
   4. 字段缺失时的降级处理
   ```

**延伸思考**：
1. 如何处理数据库表结构的版本兼容？
2. 如何平滑下线一个旧版本API？
3. gRPC/Protobuf的版本兼容如何保证？

---

---

---

##### 递进追问

- 哪些步骤必须同步确认，哪些步骤可以通过事件最终一致？
- 在重试、并发和下游不可用时，如何保证状态可恢复、可追踪？
- 规模扩大十倍后，热点、容量、隔离和降级策略如何变化？

##### 常见失分点

- 混淆领域事实、派生读模型和流程状态。
- 只描述成功路径，遗漏幂等、对账、补偿或人工处理入口。
- 把缓存、消息队列或搜索索引错误地当作交易权威来源。


#### 81. Redis、Kafka、MySQL 在系统设计里分别解决什么类型的问题？

追问：什么时候不该引入它们？


#### 82. 分布式缓存服务

##### 题干与约束
设计一个供多个业务服务使用的分布式缓存层，要求支持热点读、节点故障和缓存数据回收。

##### 答案骨架
1. 提供统一客户端与命名空间，按键哈希分片并支持副本、节点发现和连接池隔离。
2. 采用 Cache Aside 为主；缓存填充设置过期时间与随机抖动，避免集中失效。
3. 通过请求合并、互斥重建、负缓存和本地短缓存治理击穿、穿透与热点 Key。
4. 限制单租户内存、键数、对象大小和扫描速率，设置淘汰策略与容量告警。
5. 缓存故障时对核心查询回源限流、对非核心读降级；缓存不得成为交易事实的唯一权威来源。

##### 关键决策
- 根据命中率、数据新鲜度和回源成本决定缓存边界。
- 一致性采用失效、版本校验或事件刷新，避免未经界定的双写。

##### 故障与追问
热点分片失效时逐步限流和迁移热点，避免全部请求同时回源；恢复后再以受控速率预热。


#### 83. Redis 核心问题

##### 题干与约束
说明 Redis 在系统设计中的数据结构、持久化、集群与缓存风险治理。

##### 答案骨架
| 问题 | 原因 | 解决方案 |
|------|------|----------|
| **缓存穿透** | 查不存在的数据 | Bloom Filter / 缓存空值 |
| **缓存击穿** | 热点 Key 过期 | 互斥锁(Mutex) / 逻辑过期 |
| **缓存雪崩** | 大量 Key 同时过期 | 随机过期时间 / 多级缓存 |
| **Big Key** | 阻塞主线程 | 拆分 / `UNLINK` 异步删除 |

**Key 过期内存释放**：
- **惰性删除**：访问时才检查是否过期。
- **定期删除**：每秒随机抽取 20 个 Key 检查。
- **陷阱**：Redis 并非过期立即释放。从库不主动删，等主库发 DEL 命令 → 可能出现"主库内存正常，从库爆满"。

---


#### 84. ClickHouse / OLAP 选型

##### 题干与约束
说明何时使用列式分析数据库，并设计实时分析数据链路。

##### 答案骨架
- **适用**：日志分析、报表、OLAP 大屏、用户行为分析。
- **快的原因**：列式存储 + 数据有序 + 向量化执行。
- **不适合**：高并发单行查询、频繁 UPDATE。

---

### 七、安全


#### 85. 线程池设计

##### 题干与约束
为一个并发服务设计线程池隔离、队列、拒绝策略和运行治理。

##### 答案骨架
**线程数设置**：
- **CPU 密集型**：`N + 1`（N = CPU 核数）。
- **IO 密集型**：`N × (1 + Wait/Compute)` 或简化为 `2N`。

**量化估算**：
> 核心接口 RT = 500ms，目标 1 万 QPS。
> 单线程 QPS = 1000/500 = 2。
> 单机需线程数 = 10000 / 2 = 5000 → 不现实。
> → 需 **多台机器**：如 10 台，每台承担 1000 QPS，每台 500 线程。

**共享 vs 独享**：
- **独享**：核心业务（支付、下单），防止被边缘业务拖垮。
- **共享**：非核心业务共用 Common 线程池。

**监控**：暴露 `activeCount, queueSize, completedTaskCount`，队列 >80% 告警。

---


#### 86. 异步并行优化

##### 题干与约束
设计一个能降低尾延迟、控制并发并避免资源争抢的异步处理方案。

##### 答案骨架
**场景**：接口串行调用 A（用户信息）、B（积分）、C（优惠券），总耗时 T = Ta + Tb + Tc。

**优化**：`CompletableFuture` (Java) / `errgroup` (Go) 并行调用，T = max(Ta, Tb, Tc)。

**风险与应对**：
- 并行度过高 → 下游瞬时压力倍增 → 配合限流和熔断。
- 部分失败 → 降级返回默认值（如积分返回 0）。
- 长尾超时 → `orTimeout(500ms)` 强制超时。

---

### 六、中间件选型与原理


#### 87. 对象存储与文件上传下载

##### 题干与约束
设计一个支持大文件上传、断点续传、授权下载、生命周期管理和恶意文件检测的文件服务。

##### 答案骨架
1. 业务服务创建上传会话并返回短时签名地址，客户端直传对象存储，避免文件流经应用服务器。
2. 大文件采用分片、校验和与幂等分片号；服务端记录上传状态，完成后校验完整性并原子提交元数据。
3. 下载通过权限校验后生成短期签名 URL 或经受控网关转发，按租户隔离目录和配额。
4. 上传后先进入隔离区，执行类型识别、病毒扫描和内容策略校验，通过后再开放访问。
5. 对象元数据保存所有者、大小、校验和、版本、保留策略和业务引用；生命周期规则管理过期、归档与删除。

##### 关键决策
- 对象存储保存文件内容，数据库保存可查询的元数据和业务状态。
- 回调要验签且幂等；客户端声称上传完成不能代替服务端校验。

##### 故障与追问
分片超时可安全重试，未完成上传应自动清理；对象已落盘但元数据写入失败时，通过完成事件重放或定期对账修复。


## 6. 可靠性、安全与可观测性

#### 88. 线上数据异常的诊断与恢复

**题型：** 核心案例，45 分钟
**目标：** 用户反馈商品页显示旧数据、下单失败率升高、部分订单状态卡住时，设计从告警到恢复的处置流程。

**关键决策：** 关联 ID、版本、事件、状态机和读模型的诊断顺序；自动重放与人工操作的权限边界；修复后的验证证据。
**故障注入：** Outbox 消费延迟、缓存版本倒退和人工补偿同时发生。


#### 89. 如何解释高可用？

##### 题干与约束
解释限流、熔断、降级、隔离、数据保护和演练如何组成可用性设计。
##### 答案骨架
高可用不是增加实例数，而是让故障被限制、被发现、被恢复。流量层限流和隔离，依赖层超时、重试、熔断和快速失败，数据层复制、对账和补偿，运维层监控、告警、压测、演练和扩容预案；非核心能力在故障时让路给主交易。
##### 递进追问
推荐服务异常时，商品详情和下单链路分别应该如何表现？
##### 常见失分点
只说多机房；所有功能同等保护；没有监控和演练。


#### 90. 超时、重试与幂等如何协作？

##### 题干与约束
下游偶发超时，调用方需要提高成功率但不能重复创建订单、扣库存或支付。
##### 答案骨架
超时防止资源无限等待，重试处理可恢复的瞬时失败，幂等确保重复请求产生相同业务结果。调用方使用有限次数、退避和抖动；服务端用请求键、唯一约束、状态机或去重记录收敛副作用，并在未知结果时查询最终状态而非盲目重试。
##### 递进追问
支付请求超时但渠道可能已扣款，客户端能否重试？服务端应返回什么？
##### 常见失分点
所有异常都重试；只在客户端做幂等；没有重试上限和观测。


#### 91. 什么时候用熔断，什么时候用降级？

##### 题干与约束
推荐、通知和支付渠道等依赖发生持续失败，主业务需要保持可用。
##### 答案骨架
熔断在错误率或延迟异常时快速拒绝调用，保护调用方资源并等待探测恢复；降级是在非核心能力不可用时提供简化结果或关闭功能，保护核心业务。例如详情页可移除推荐模块，支付渠道异常应切换渠道、保留处理中状态或转人工，不能伪造成功。
##### 递进追问
通知服务熔断后，怎样保证交易状态仍可被用户查询和后续补发？
##### 常见失分点
把熔断等同于服务下线；对支付直接返回成功；没有恢复和补偿策略。


#### 92. 如何设计服务间的调用链路追踪？

##### 题干与约束

微服务架构下，一个用户请求可能经过十几个服务。当出现问题时，如何快速定位是哪个服务出了问题？请设计分布式追踪方案。

##### 答案骨架


**问题描述**：
微服务架构下，一个用户请求可能经过十几个服务。当出现问题时，如何快速定位是哪个服务出了问题？请设计分布式追踪方案。

**答案**：

**问题分析**：
链路追踪的核心挑战：
1. 如何关联一次请求涉及的所有服务调用
2. 如何记录调用链路的详细信息（耗时、参数、结果）
3. 如何在性能开销和可观测性之间平衡
4. 如何快速检索和分析海量追踪数据

**方案一：自研追踪系统**

核心思路：
基于唯一TraceID串联整个调用链，每个服务记录SpanID。

设计：
- **TraceID**：全局唯一ID，标识一次完整请求
- **SpanID**：服务内部的调用单元ID
- **传递机制**：通过HTTP Header或RPC Context传递
- **数据收集**：每个服务将Span数据异步上报
- **存储分析**：存储到Elasticsearch，Kibana可视化

实现步骤：
1. 网关生成TraceID
2. 服务间传递TraceID和ParentSpanID
3. 每个服务记录：服务名、方法名、开始时间、结束时间、状态
4. 异步上报到追踪系统

优点：
- 完全可控，可定制
- 无外部依赖
- 数据私密性好

缺点：
- 开发成本高
- 需要所有服务埋点
- 维护成本高

**方案二：使用开源APM（如Skywalking）**

核心思路：
使用Java Agent无侵入式采集调用链数据。

设计：
- **Agent方式**：通过JavaAgent字节码增强自动埋点
- **OAP Server**：接收、分析、存储追踪数据
- **UI**：可视化展示调用链拓扑、性能指标
- **告警**：支持性能阈值告警

优点：
- 无侵入，不需要改代码
- 功能完善（拓扑、指标、告警）
- 社区活跃，文档丰富
- 支持多种框架（Spring、Dubbo、gRPC）

缺点：
- Agent有一定性能开销
- 不支持非Java语言
- 定制化能力有限

**方案三：使用云厂商APM（如阿里云ARMS）**

核心思路：
使用云厂商提供的APM服务，开箱即用。

设计：
- **SDK集成**：引入SDK，自动上报追踪数据
- **云端分析**：云厂商负责数据存储和分析
- **控制台**：提供丰富的可视化和分析能力
- **AI诊断**：智能分析性能瓶颈

优点：
- 开箱即用，实施快
- 功能强大（AI诊断、实时监控）
- 无需自建基础设施
- 技术支持好

缺点：
- 成本高（按量付费）
- 数据外传有安全风险
- 被云厂商锁定

**方案对比**：

| 维度 | 自研 | Skywalking | 云APM |
|------|------|-----------|-------|
| 实施成本 | ★★☆☆☆ | ★★★★☆ | ★★★★★ |
| 功能丰富度 | ★★★☆☆ | ★★★★☆ | ★★★★★ |
| 定制能力 | ★★★★★ | ★★★☆☆ | ★★☆☆☆ |
| 运维成本 | ★★☆☆☆ | ★★★☆☆ | ★★★★★ |

**推荐方案**：
根据团队规模选择：
- **大团队**（100+人）：自研追踪系统，可定制化
- **中等团队**（20-100人）：使用Skywalking，开源免费
- **小团队**（<20人）：使用云APM，开箱即用

实施要点：
1. **采样策略**：不是所有请求都追踪，按比例采样（如1%）
2. **性能优化**：异步上报，避免阻塞主流程
3. **标准化**：定义统一的TraceID、SpanID规范
4. **关键节点**：重点追踪慢查询、外部调用、错误日志
5. **告警配置**：P99延迟、错误率等关键指标告警

**延伸思考**：
1. 如何在不影响性能的前提下采集足够的追踪数据？
2. 如何处理跨语言服务的追踪？
3. 追踪数据如何与日志、指标关联？

---

##### 递进追问

- 哪些步骤必须同步确认，哪些步骤可以通过事件最终一致？
- 在重试、并发和下游不可用时，如何保证状态可恢复、可追踪？
- 规模扩大十倍后，热点、容量、隔离和降级策略如何变化？

##### 常见失分点

- 混淆领域事实、派生读模型和流程状态。
- 只描述成功路径，遗漏幂等、对账、补偿或人工处理入口。
- 把缓存、消息队列或搜索索引错误地当作交易权威来源。


#### 93. 为什么分布式系统必须重视超时、重试和幂等？

追问：如果客户端重试导致重复下单，你会怎么兜底？


#### 94. 认证鉴权与会话管理系统

##### 题干与约束
设计一个支持 Web 与移动端登录、单点登录、权限校验、令牌续期和账号撤销的身份认证系统。

##### 答案骨架
1. 统一身份主体、凭据、会话和授权策略模型，密码使用带盐的强哈希算法保存，并支持多因素认证。
2. 登录后签发短期访问令牌与可轮换的刷新凭据；刷新时检测重放并更新会话版本。
3. 服务端按资源和动作执行 RBAC 或 ABAC 授权，敏感操作增加二次校验并写入审计日志。
4. 通过 OAuth/OIDC 与企业身份提供方建立单点登录；验证签名、受众、发行方、有效期和随机数。
5. 退出、改密、账号冻结或风险事件触发会话撤销；高风险接口支持令牌版本校验或撤销列表。

##### 关键决策
- 无状态 JWT 降低在线校验成本，但立即撤销需要额外状态机制。
- 访问令牌短时有效，刷新令牌只存哈希并绑定设备或会话。

##### 故障与追问
身份提供方超时不应默认放行；已签发会话的撤销事件需可靠传播，权限变更应有生效时限和审计证据。


#### 95. 常见 Web 攻防

##### 题干与约束
设计 Web 应用的主要安全边界与攻击防护方案。

##### 答案骨架
| 攻击 | 防御 |
|------|------|
| **XSS** | 输出转义、CSP 头、HttpOnly Cookie |
| **CSRF** | CSRF Token、SameSite Cookie |
| **SQL 注入** | 预编译（`#{}` 而非 `${}`） |
| **重放攻击** | 签名 + 时间戳 + nonce + 设备指纹 |


#### 96. HTTPS 握手与加密

##### 题干与约束
解释 TLS/HTTPS 握手、证书验证和密钥协商，并说明常见故障排查点。

##### 答案骨架
1. 服务端下发证书（含公钥）。
2. 客户端验证证书合法性。
3. 客户端生成随机对称密钥，用公钥加密传给服务端。
4. 后续通信使用对称加密。

**一句话**：非对称加密传密钥，对称加密传数据。

---

### 八、可观测性


#### 97. 接口突然变慢排查

##### 题干与约束
线上接口 P99 延迟突然升高，设计定位、止血和恢复流程。

##### 答案骨架
1. **看链路 (Tracing)**：哪一跳耗时突增？
2. **看指标 (Metrics)**：DB CPU 飙升？MQ 积压？线程池满？
3. **看日志 (Logging)**：是否有异常堆栈？
4. **对比变更**：最近是否上线/扩容/配置变更？

**止血第一**：先回滚或切流量，再定位根因。

---

### 九、云原生与弹性架构


#### 98. SLI、SLO 与错误预算

##### 题干与约束
为一个面向用户的在线服务定义可衡量的服务目标，并说明目标如何影响发布、告警和可靠性投入。

##### 答案骨架
1. 从用户旅程选择可观察的 SLI，例如成功率、延迟分位数和新鲜度，并写清分母、过滤条件与统计窗口。
2. 为每项 SLI 定义目标值和窗口形成 SLO；目标反映用户承诺，不直接等同于机器正常率。
3. 将错误预算定义为目标允许的失败额度，并按服务等级与时间窗口计算消耗速度。
4. 设置面向用户影响和快速燃烧率的告警；预算充足时允许正常发布，快速消耗时降低变更风险并优先修复可靠性。
5. 定期复核目标是否对应真实用户体验，并检查测量盲点、采样偏差和依赖责任。

##### 关键决策
- 指标必须能从用户体验解释，不能只用 CPU 或实例存活作为服务目标。
- 用多窗口燃烧率平衡快速发现与告警噪声。

##### 故障与追问
若核心用户旅程成功率下降但基础设施指标正常，应以用户可见 SLI 触发处置，并定位业务依赖和数据链路。


#### 99. 故障演练与混沌工程

##### 题干与约束
设计一个逐步验证服务恢复能力的故障演练方案，避免演练扩大为真实生产事故。

##### 答案骨架
1. 提出可证伪假设，例如一个可用区失效后，核心请求应在目标时间内恢复。
2. 先在测试环境或小流量范围注入单一故障，定义服务影响上限、观测信号和停止条件。
3. 验证告警、自动切换、降级、数据一致性和人工处置流程是否符合预期。
4. 演练结束后核对用户影响、数据差异、恢复时间和未触发的告警，形成责任人和期限明确的改进项。
5. 从只读依赖、单实例和影子流量逐步扩展，不同时注入多个未经验证的故障。

##### 关键决策
- 演练目标是验证具体的恢复假设，而不是展示工具或制造故障。
- 必须具备实时停止开关、值守人员和回退步骤。

##### 故障与追问
若错误率、积压或数据差异超过预设阈值，立即终止注入并恢复基线；故障恢复后确认状态收敛再结束演练。


#### 100. 日志采集与实时分析平台

##### 题干与约束
设计一个多租户日志平台，支持海量写入、实时检索、告警、成本控制和数据保留策略。

##### 答案骨架
1. 采集 Agent 本地缓冲并批量压缩，接入网关执行身份校验、限流和字段规范化。
2. 消息流作为削峰缓冲，按租户或服务分区；消费者幂等写入按时间分区的索引与冷热存储。
3. 交互查询限制时间范围、扫描量和并发，聚合任务与在线检索隔离资源。
4. 告警规则使用窗口聚合和去重分组，明确延迟、误报和通知升级策略。
5. 按租户配置保留期限、采样、索引字段和配额，支持删除、归档与审计。

##### 关键决策
- 高基数字段不能无界索引；原始日志、索引和指标应按不同查询需要分层。
- 采集与检索隔离，避免检索尖峰影响日志写入。

##### 故障与追问
下游存储积压时先保护采集和告警关键字段，再对低价值日志采样或延迟处理；公开积压水位与数据丢弃量。
