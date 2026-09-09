# 命名规范

primer v2 源码文件使用以下文件名模式：

| 类别 | 模式 | 示例 |
| --- | --- | --- |
| LeetCode | `<id>_<english_slug>.<ext>` | `1_two_sum.cc` |
| 剑指 Offer | `offer<id>_<english_slug>.cc` | `offer45_straight_in_poker.cc` |
| 其他专题 | 小写专题前缀加 `snake_case` 命名 | `graph_zero_one_bfs.cc` |

## 规则

- 只使用小写 ASCII 字母、数字和下划线。
- 非 LeetCode 文件把专题前缀放在最前面。
- 新文件名不要使用空格、大写字母或中英混合片段；LeetCode 文件必须包含题号和英文简称。
- 在每个引用该题的索引和 README 中使用同一个文件名。
