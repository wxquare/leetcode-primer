<div align="center">

# interview-primer

**算法与系统设计面试学习指南**

[算法面试](algorithm-interview/README.md) · [系统设计面试](system-design-interview/README.md) · [复习方法](guides/review-method.md) · [贡献指南](guides/contribution-guide.md)

</div>

---

本仓库把面试准备分为两个学习方向。算法方向提供题解、题单、专题模板和阶段化路线；系统设计方向整理后端基础、系统设计题库与工程示例。

## 选择学习方向

| 方向 | 入口 | 内容 |
| --- | --- | --- |
| 算法面试 | [算法学习入口](algorithm-interview/README.md) | LeetCode、剑指 Offer、Top 100/300、完整题单、算法模板与实现。 |
| 系统设计面试 | [系统设计学习入口](system-design-interview/README.md) | 后端基础、电商与通用系统设计、AI/Agent 工程题库和并发/设计示例。 |

建议按对应领域 README 中的路线学习，完成题目后记录薄弱点，再按 [1、3、7、14 天复习节奏](guides/review-method.md)回收错题。个人复习记录保存在本地 `.local/reviews/`，不会提交到仓库；可参考[复习记录示例](guides/reviews/review.example.md)。

## 快速上手

题解和示例以独立源码文件组织，没有统一构建系统。当前 GitHub 仓库地址仍为 `wxquare/leetcode-primer`：

```bash
git clone https://github.com/wxquare/leetcode-primer.git
cd leetcode-primer

# 编译并运行 KMP 示例
g++ -std=c++17 -O2 "algorithm-interview/implementations/src/string_kmp.cc" -o /tmp/string_kmp
/tmp/string_kmp
```

开始记录复习进度：

```bash
mkdir -p .local/reviews
cp guides/reviews/review.example.md .local/reviews/YYYY-MM-DD.md
```

题目笔记可参考[题目笔记模板](guides/problem-note-template.md)。

## 仓库结构

```text
interview-primer/
├── algorithm-interview/       # 算法题解、路线、索引、模板和算法实现
├── system-design-interview/   # 后端基础、系统设计题库和工程示例
├── guides/                    # 跨领域复习方法、贡献规范和笔记模板
└── tools/                     # 文档检查与源码测试工具
```

## 参与维护

- 算法题目按主要解法归入六个专题；完整题单由 [LeetCode README](algorithm-interview/leetcode/README.md) 维护，多维索引通过链接引用。
- 新增内容时同步更新所属目录 README 和对应的题单或索引，具体规则见[贡献指南](guides/contribution-guide.md)。
- 文件命名遵循[命名规范](guides/naming-conventions.md)。文档调整后运行 `python3 tools/check_markdown_consistency.py` 和 `python3 -m unittest discover -s tools -p 'test_*.py'`。
