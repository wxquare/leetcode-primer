# 2026-09-10 随机抽题复习记录

> 后续复习记录统一追加到本文件，并在每个日期小节中注明日期。

题库来源：[leetcode/README.md](../../leetcode/README.md)。本轮随机抽取 10 题，已做题不作为后续首次抽题候选；需要提示或尚未完成的题目保留在复习队列中。

## 今日结果

| Problem | 今日结果 | Review | 解法要点 / 备注 | 下次复习 |
| --- | --- | --- | --- | --- |
| [26. 删除有序数组中的重复项](https://leetcode.cn/problems/remove-duplicates-from-sorted-array) | 独立完成 | `review` | 快慢指针；`left` 维护去重后数组的尾部。 | 2026-09-11 |
| [83. 删除排序链表中的重复元素](https://leetcode.cn/problems/remove-duplicates-from-sorted-list) | 独立完成 | `review` | 有序链表；重复时跳过节点，不重复时推进指针。 | 2026-09-11 |
| [205. 同构字符串](https://leetcode.cn/problems/isomorphic-strings) | 独立完成 | `review` | 双向字符映射，保证映射具有一一对应关系。 | 2026-09-11 |
| [517. 超级洗衣机](https://leetcode.cn/problems/super-washing-machines) | 根据提示完成 | `review` | 前缀平衡；答案取 `abs(balance)` 与正向供给量的最大值。 | 2026-09-11 |

## 尚未完成的随机题

以下题目已抽到，但今天尚未提交结果，暂不改变其复习状态：

| Problem | Review | 后续动作 |
| --- | --- | --- |
| [687. 最长同值路径](https://leetcode.cn/problems/longest-univalue-path) | `new` | 独立完成后补充结果 |
| [769. 最多能完成排序的块](https://leetcode.cn/problems/max-chunks-to-make-sorted) | `new` | 独立完成后补充结果 |
| [924. 尽量减少恶意软件的传播](https://leetcode.cn/problems/minimize-malware-spread) | `new` | 独立完成后补充结果 |
| [2003. 每棵子树内缺失的最小基因值](https://leetcode.cn/problems/smallest-missing-genetic-value-in-each-subtree) | `new` | 独立完成后补充结果 |
| [2707. 字符串中的额外字符](https://leetcode.cn/problems/extra-characters-in-a-string) | `new` | 独立完成后补充结果 |
| [2742. 给墙壁刷油漆](https://leetcode.cn/problems/painting-the-walls) | `new` | 独立完成后补充结果 |

## 下一轮筛选规则

- 优先处理上表中仍为 `new` 的 6 道题。
- `517` 因为使用过提示，下一次按 `review` 处理，不直接标记为 `mastered`。
- 26、83、205 按 `1 → 3 → 7 → 14` 天节奏复习；若后续无法独立回忆，则改为 `mistake` 并重新从 1 天节点开始。
