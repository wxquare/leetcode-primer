<div align="center">

# leetcode-primer

**面向求职面试的 C++ 算法题解、学习路线与间隔复盘仓库**

![LeetCode 题单](https://img.shields.io/badge/LeetCode-666%20题-brightgreen)
![主要语言](https://img.shields.io/badge/主要语言-C%2B%2B-blue)

[开始刷题](guides/roadmap/00-start-here.md) · [Top 100](leetcode/top100.md) · [Top 300](leetcode/top300.md) · [完整题单](guides/indexes/leetcode-problems.md) · [后端与系统设计](system-design/README.md) · [复习方法](guides/review-method.md)

</div>

---

## 为面试而学，而不只是刷题

这是一个以 C++ 算法题解为主的学习与复盘仓库，收录 LeetCode、剑指 Offer、算法模板、数据结构实现，以及少量并发和工程练习。它把题解组织为一条可执行的学习路线：**按阶段建立模型，按模式专项练习，再用错题复盘巩固面试表现**。

适合准备算法面试、后端基础面试和系统设计面试，或需要快速回顾常用模板的读者。

## 后端与系统设计

仓库同时整理后端面试中的核心基础与系统设计题目。[核心后端基础题](system-design/question-bank/core-backend-foundations.md)覆盖 12 个技术领域，共 200 个主题、1000 道题，采用“问题、答案、追问”三段式整理。

## 面试冲刺，从这里开始

| 你的目标 | 推荐入口 | 你会得到什么 |
| --- | --- | --- |
| 从零建立刷题顺序 | [学习路线](guides/roadmap/00-start-here.md) | 基础阶段、核心模式、高级专题与面试冲刺的阶段化安排。 |
| 优先攻克最常考题 | [面试高频 Top 100](leetcode/top100.md) | 高频题与对应的主要考点、解题思路。 |
| 做更完整的面试覆盖 | [面试高频 Top 300](leetcode/top300.md) | 面向系统复习的重点题单。 |
| 按目标补齐题目 | [完整 LeetCode 题单](guides/indexes/leetcode-problems.md) | 666 道去重题目；本地有源码时直达源码，没有时链接原题。 |
| 按解法查缺补漏 | [按模式](guides/indexes/problems-by-pattern.md) / [按主题](guides/indexes/problems-by-topic.md) / [按难度](guides/indexes/problems-by-difficulty.md) / [按来源](guides/indexes/problems-by-source.md) | 从双指针、滑动窗口、DP、图论等维度定位练习。 |

> **建议的冲刺顺序：** 先沿学习路线补齐基础，再完成 Top 100；面试前按模式回顾薄弱点，用 Top 300 和错题记录做混合练习。

## 学习与复盘闭环

```text
选择专题或高频题 → 独立完成并复盘思路 → 记录错误原因 → 按间隔重复回顾 → 回到混合题检验
```

- 使用 `new`、`review`、`mastered`、`mistake` 标记掌握状态。
- 按 `1 → 3 → 7 → 14` 天节奏复习；失误题回到复习队列。
- 个人记录放在本地 `.local/reviews/`，不会提交到仓库。可从[复习记录示例](guides/reviews/review.example.md)开始，并阅读完整的[复习方法](guides/review-method.md)。

## 快速上手

本仓库按题目和专题保存相对独立的源码，没有统一构建系统。克隆后可直接编译带有 `main` 函数的示例文件：

```bash
git clone https://github.com/wxquare/leetcode-primer.git
cd leetcode-primer

# 示例：编译并运行 KMP 实现
g++ -std=c++17 -O2 "其它常见的题目/src/string_kmp.cc" -o /tmp/string_kmp
/tmp/string_kmp
```

开始记录自己的复习进度：

```bash
mkdir -p .local/reviews
cp guides/reviews/review.example.md .local/reviews/YYYY-MM-DD.md
```

填写后的记录仅保留在本地；题目笔记可参考[题目笔记模板](guides/problem-note-template.md)。

## 内容地图

```text
leetcode-primer/
├── guides/                         # 学习路线、多维索引、复习与协作规范
│   ├── roadmap/                    # 阶段化学习路线
│   └── indexes/                    # 题单、主题、模式、难度与来源索引
├── leetcode/                       # LeetCode 题解，按六个主要主题归档
│   ├── 基础算法/ 数据结构/ 数学/
│   └── 搜索/ 动态规划/ 图论/
├── 剑指offer/                      # 《剑指 Offer》66 题，源码在 src/
├── 其它常见的题目/                  # 高频题、模板、数据结构、设计模式与并发练习
│   └── src/                        # C++、Go、Python、Lua 等源码/头文件
├── template/                       # Markdown 学习模板与跨分类专题
└── system-design/                 # 后端基础与系统设计面试
    └── question-bank/              # 分专题题库
```

| 内容 | 入口 | 说明 |
| --- | --- | --- |
| LeetCode 题解 | [题目索引](leetcode/README.md) | 按六大主要主题归档的题解、题单与源码。 |
| 剑指 Offer | [题目说明](剑指offer/README.md) | 66 个 C++ 题解，源码命名为 `offerN.cc`。 |
| 常见题与工程练习 | [目录索引](其它常见的题目/README.md) | 图论、字符串、区间查询、动态规划、并发等多语言实现。 |
| 算法模板 | [模板导航](template/README.md) | 六大分类学习文档，以及区间查询与统计、路径问题等跨分类专题。 |
| 模板索引 | [按主题查看模板](guides/indexes/templates-by-topic.md) | 按专题定位可复用的学习模板。 |

## 阅读与贡献约定

- LeetCode 源码以主导解法归入基础算法、数据结构、数学、搜索、动态规划或图论；跨分类题目通过[主题索引](guides/indexes/problems-by-topic.md)和[模式索引](guides/indexes/problems-by-pattern.md)交叉查找。
- LeetCode 文件通常命名为 `<题号>_<english_slug>.<扩展名>`；其它常见题目使用小写 `snake_case`。详细规则见[命名规范](guides/naming-conventions.md)。
- 新增题目时，请同步更新源码、所属目录 README 和至少一条索引；具体要求见[贡献指南](guides/contribution-guide.md)。
- 每个目录的 README 是该目录的事实入口；需要完整模板、题单或规则时，优先沿上方链接进入对应的权威文档。
