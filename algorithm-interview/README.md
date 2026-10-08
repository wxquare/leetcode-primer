# 算法面试

本目录集中管理算法面试所需的学习路线、题解、题单、专题模板和可复用实现。按学习路线建立基础模型，再用题单训练覆盖度，并通过专题模板和复习机制巩固。

## 学习入口

| 目标 | 入口 | 用途 |
| --- | --- | --- |
| 安排学习顺序 | [算法学习路线](guides/roadmap/00-start-here.md) | 从基础到核心模式、高级主题和面试冲刺。 |
| 先做高频题 | [Top 100](leetcode/top100.md) | 优先覆盖常见面试题。 |
| 扩大练习范围 | [Top 300](leetcode/top300.md) | 按阶段进行更完整的面试复习。 |
| 查找全部题目 | [完整 LeetCode 题单](guides/indexes/leetcode-problems.md) | 按题号定位题目、本地源码或原题链接。 |
| 按方法查漏补缺 | [模式](guides/indexes/problems-by-pattern.md) · [主题](guides/indexes/problems-by-topic.md) · [难度](guides/indexes/problems-by-difficulty.md) · [来源](guides/indexes/problems-by-source.md) | 从不同维度筛选练习。 |
| 查可复用模板 | [模板目录](templates/README.md) · [按主题索引](guides/indexes/templates-by-topic.md) | 阅读推导、复杂度、易错点和复习安排。 |

## 内容分区

- [LeetCode 题解](leetcode/README.md)：按基础算法、数据结构、数学、搜索、动态规划和图论归档；此 README 是完整题单的权威来源。
- [剑指 Offer](剑指offer/README.md)：66 道题解及其源码索引。
- [算法实现](implementations/README.md)：不绑定单道 LeetCode 题目的排序、图论、数据结构和算法模板实现。
- [学习模板](templates/README.md)：按专题组织的学习材料，与源码分开维护。

## 维护约定

- README 维护完整题单；模板文档维护系统推导和可复用方法，索引只链接权威来源。
- 题单每行一个题目并保留 `【关键点/解题思路】` 标记；重新分类时核对题号集合和出现次数。
- 算法专题与题单规则见仓库 [AGENTS.md](../AGENTS.md)，跨领域文档和贡献规范见[贡献指南](../guides/contribution-guide.md)。
