# 剑指 Offer 题目索引

本目录收录 66 道经典《剑指 Offer》题目的 C++ 实现，源码统一位于 [`src/`](src/)。难度为学习难度（★ 到 ★★★★★），综合算法技巧、边界处理与实现复杂度评估；函数签名以当前源码中的公开入口为准。

| 编号 | 题目 | 题目含义 | 函数签名 | 难度 |
| --- | --- | --- | --- | --- |
| 1 | [二维数组中的查找](src/offer1.cc) | 在行、列均递增的二维数组中查找目标值。 | `bool Find(int target, vector<vector<int>> array)` | ★★ |
| 2 | [替换空格](src/offer2.cc) | 将字符串中的空格原地替换为 `%20`。 | `void replaceSpace(char* str, int length)` | ★ |
| 3 | [从尾到头打印链表](src/offer3.cc) | 按链表逆序返回节点值。 | `vector<int> printListFromTailToHead(ListNode* head)` | ★ |
| 4 | [重建二叉树](src/offer4.cc) | 由前序与中序遍历重建二叉树。 | `TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin)` | ★★★ |
| 5 | [用两个栈实现队列](src/offer5.cc) | 用两个栈实现队列的入队与出队。 | `void push(int node)` / `int pop()` | ★★ |
| 6 | [旋转数组的最小数字](src/offer6.cc) | 在旋转后的非递减数组中寻找最小值。 | `int minNumberInRotateArray(vector<int> rotateArray)` | ★★ |
| 7 | [斐波那契数列](src/offer7.cc) | 计算第 `n` 项斐波那契数。 | `int Fibonacci(int n)` | ★ |
| 8 | [跳台阶](src/offer8.cc) | 每次跳 1 或 2 阶，计算到达第 `n` 阶的方法数。 | `int jumpFloor(int number)` | ★ |
| 9 | [变态跳台阶](src/offer9.cc) | 每次可跳 1 到 `n` 阶，计算到达第 `n` 阶的方法数。 | `int jumpFloorII(int number)` | ★★ |
| 10 | [矩形覆盖](src/offer10.cc) | 用 `2×1` 小矩形覆盖 `2×n` 大矩形的方案数。 | `int rectCover(int number)` | ★ |
| 11 | [二进制中 1 的个数](src/offer11.cc) | 统计整数二进制表示中置位位的数量。 | `int NumberOf1(int n)` | ★★ |
| 12 | [数值的整数次方](src/offer12.cc) | 实现幂函数，处理负指数与快速幂。 | `double Power(double base, int exponent)` | ★★ |
| 13 | [调整数组顺序使奇数位于偶数前面](src/offer13.cc) | 保持相对顺序地把奇数放在偶数之前。 | `void reOrderArray(vector<int>& array)` | ★★ |
| 14 | [链表中倒数第 k 个结点](src/offer14.cc) | 通过双指针找到链表倒数第 `k` 个节点。 | `ListNode* FindKthToTail(ListNode* pListHead, unsigned int k)` | ★★ |
| 15 | [反转链表](src/offer15.cc) | 原地反转单链表。 | `ListNode* ReverseList(ListNode* pHead)` | ★★ |
| 16 | [合并两个排序的链表](src/offer16.cc) | 合并两个递增链表。 | `ListNode* Merge(ListNode* pHead1, ListNode* pHead2)` | ★★ |
| 17 | [树的子结构](src/offer17.cc) | 判断一棵树是否包含另一棵树的结构。 | `bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)` | ★★★ |
| 18 | [二叉树的镜像](src/offer18.cc) | 原地交换每个节点的左右子树。 | `void Mirror(TreeNode* pRoot)` | ★ |
| 19 | [顺时针打印矩阵](src/offer19.cc) | 按顺时针螺旋顺序遍历矩阵。 | `vector<int> printMatrix(vector<vector<int>>& matrix)` | ★★ |
| 20 | [包含 min 函数的栈](src/offer20.cc) | 在常数时间内取得栈内最小值。 | `push(int)` / `pop()` / `top()` / `min()` | ★★ |
| 21 | [栈的压入、弹出序列](src/offer21.cc) | 判断一个序列是否可能是给定入栈序列的出栈序列。 | `bool IsPopOrder(vector<int> pushV, vector<int> popV)` | ★★ |
| 22 | [从上往下打印二叉树](src/offer22.cc) | 对二叉树进行层序遍历。 | `vector<int> PrintFromTopToBottom(TreeNode* root)` | ★ |
| 23 | [二叉搜索树的后序遍历序列](src/offer23.cc) | 验证数组是否可能是 BST 的后序遍历。 | `bool VerifySquenceOfBST(vector<int> sequence)` | ★★★ |
| 24 | [二叉树中和为某一值的路径](src/offer24.cc) | 找出根到叶路径和等于目标值的所有路径。 | `vector<vector<int>> FindPath(TreeNode* root, int expectNumber)` | ★★★ |
| 25 | [复杂链表的复制](src/offer25.cc) | 深拷贝含随机指针的链表。 | `RandomListNode* Clone(RandomListNode* pHead)` | ★★★ |
| 26 | [二叉搜索树与双向链表](src/offer26.cc) | 将 BST 原地转换为有序双向链表。 | `TreeNode* Convert(TreeNode* pRootOfTree)` | ★★★ |
| 27 | [字符串的排列](src/offer27.cc) | 生成字符串的所有不重复排列。 | `vector<string> Permutation(string str)` | ★★★ |
| 28 | [数组中出现次数超过一半的数字](src/offer28.cc) | 找出出现次数超过数组长度一半的元素。 | `int MoreThanHalfNum_Solution(vector<int> number)` | ★★ |
| 29 | [最小的 k 个数](src/offer29.cc) | 从数组中选出最小的 `k` 个元素。 | `vector<int> GetLeastNumbers_Solution(vector<int> input, int k)` | ★★ |
| 30 | [连续子数组的最大和](src/offer30.cc) | 求连续子数组的最大和。 | `int FindGreatestSumOfSubArray(vector<int> array)` | ★★ |
| 31 | [整数中 1 出现的次数](src/offer31.cc) | 统计 `1` 到 `n` 中数字 `1` 出现的总次数。 | `int NumberOf1Between1AndN_Solution(int n)` | ★★★ |
| 32 | [把数组排成最小的数](src/offer32.cc) | 重排非负整数，使拼接结果最小。 | `string PrintMinNumber(vector<int> numbers)` | ★★★ |
| 33 | [丑数](src/offer33.cc) | 求只含 2、3、5 质因子的第 `n` 个丑数。 | `int GetUglyNumber_Solution(int index)` | ★★ |
| 34 | [第一个只出现一次的字符](src/offer34.cc) | 返回字符串中首个只出现一次字符的位置。 | `int FirstNotRepeatingChar(string str)` | ★★ |
| 35 | [数组中的逆序对](src/offer35.cc) | 统计数组中满足 `i < j` 且 `a[i] > a[j]` 的对数。 | `int InversePairs(vector<int> data)` | ★★★★ |
| 36 | [两个链表的第一个公共结点](src/offer36.cc) | 找到两条单链表相交的首个节点。 | `ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2)` | ★★ |
| 37 | [数字在排序数组中出现的次数](src/offer37.cc) | 统计有序数组中目标值的出现次数。 | `int GetNumberOfK(vector<int> data, int k)` | ★★ |
| 38 | [二叉树的深度](src/offer38.cc) | 计算二叉树的最大深度。 | `int TreeDepth(TreeNode* root)` | ★ |
| 39 | [平衡二叉树](src/offer39.cc) | 判断二叉树任意节点的左右子树高度差是否不超过 1。 | `bool IsBalanced_Solution(TreeNode* pRoot)` | ★★★ |
| 40 | [数组中只出现一次的数字](src/offer40.cc) | 在其余数字出现两次时，找出两个只出现一次的数字。 | `void FindNumsAppearOnce(vector<int> data, int* num1, int* num2)` | ★★★ |
| 41 | [和为 S 的连续正数序列](src/offer41.cc) | 找出所有和为目标值的连续正整数序列。 | `vector<vector<int>> FindContinuousSequence(int sum)` | ★★ |
| 42 | [和为 S 的两个数字](src/offer42.cc) | 在递增数组中找和为目标值的一对数字。 | `vector<int> FindNumbersWithSum(vector<int> array, int sum)` | ★★ |
| 43 | [左旋转字符串](src/offer43.cc) | 将字符串向左循环移动 `n` 位。 | `string LeftRotateString(string str, int n)` | ★ |
| 44 | [翻转单词顺序列](src/offer44.cc) | 保持单词内部顺序，翻转整句的单词顺序。 | `string ReverseSentence(string str)` | ★★ |
| 45 | [扑克牌顺子](src/offer45.cc) | 判断一组含大小王的牌能否组成顺子。 | `bool IsContinuous(vector<int> numbers)` | ★★ |
| 46 | [圆圈中最后剩下的数](src/offer46.cc) | 求约瑟夫环问题的最后剩余位置。 | `int LastRemaining_Solution(int n, int m)` | ★★★ |
| 47 | [求 1+2+…+n](src/offer47.cc) | 不使用常规循环/条件语句计算累加和。 | `int Sum_Solution(int n)` | ★★ |
| 48 | [不用加减乘除做加法](src/offer48.cc) | 使用位运算实现整数加法。 | `int Add(int num1, int num2)` | ★★ |
| 49 | [把字符串转换成整数](src/offer49.cc) | 实现带符号与非法输入处理的字符串转整数。 | `int StrToInt(string str)` | ★★★ |
| 50 | [数组中重复的数字](src/offer50.cc) | 在给定范围数组中找出任一重复元素。 | `bool duplicate(int numbers[], int length, int* duplication)` | ★★ |
| 51 | [构建乘积数组](src/offer51.cc) | 构造每项等于其余元素乘积的数组，且不使用除法。 | `vector<int> multiply(const vector<int>& A)` | ★★★ |
| 52 | [正则表达式匹配](src/offer52.cc) | 支持 `.` 与 `*` 的字符串模式匹配。 | `bool match(char* str, char* pattern)` | ★★★★ |
| 53 | [表示数值的字符串](src/offer53.cc) | 判断字符串是否表示合法数值（符号、小数、指数）。 | `bool isNumeric(char* string)` | ★★★ |
| 54 | [字符流中第一个不重复字符](src/offer54.cc) | 在线插入字符并查询第一个只出现一次的字符。 | `void Insert(char ch)` / `char FirstAppearingOnce()` | ★★ |
| 55 | [链表中环的入口结点](src/offer55.cc) | 找到有环链表的入环节点。 | `ListNode* EntryNodeOfLoop(ListNode* pHead)` | ★★★ |
| 56 | [删除链表中重复的结点](src/offer56.cc) | 删除有序链表中值重复的全部节点。 | `ListNode* deleteDuplication(ListNode* pHead)` | ★★★ |
| 57 | [二叉树的下一个结点](src/offer57.cc) | 给定含父指针节点，找到其中序遍历后继。 | `TreeLinkNode* GetNext(TreeLinkNode* pRoot)` | ★★★ |
| 58 | [对称的二叉树](src/offer58.cc) | 判断二叉树是否关于根节点左右对称。 | `bool isSymmetrical(TreeNode* pRoot)` | ★★ |
| 59 | [按之字形顺序打印二叉树](src/offer59.cc) | 按层遍历二叉树，并交替改变每层输出方向。 | `vector<vector<int>> Print(TreeNode* pRoot)` | ★★ |
| 60 | [把二叉树打印成多行](src/offer60.cc) | 按层输出二叉树，每层形成一个数组。 | `vector<vector<int>> Print(TreeNode* pRoot)` | ★★ |
| 61 | [序列化二叉树](src/offer61.cc) | 将二叉树编码为字符串，并从字符串恢复结构。 | `char* Serialize(TreeNode* root)` / `TreeNode* Deserialize(char* str)` | ★★★★ |
| 62 | [二叉搜索树的第 k 个结点](src/offer62.cc) | 找到 BST 中第 `k` 小的节点。 | `TreeNode* KthNode(TreeNode* root, int k)` | ★★ |
| 63 | [数据流中的中位数](src/offer63.cc) | 在线插入数据并查询当前中位数。 | `void Insert(int num)` / `double GetMedian()` | ★★★ |
| 64 | [滑动窗口的最大值](src/offer64.cc) | 求数组每个固定长度窗口的最大值。 | `vector<int> maxInWindows(const vector<int>& num, unsigned int size)` | ★★★ |
| 65 | [矩阵中的路径](src/offer65.cc) | 判断矩阵中是否存在匹配给定字符串的相邻路径。 | `bool hasPath(char* matrix, int rows, int cols, char* str)` | ★★★ |
| 66 | [机器人的运动范围](src/offer66.cc) | 统计数字位和受限时机器人可到达的格子数量。 | `int movingCount(int threshold, int rows, int cols)` | ★★★ |

## 说明

- `ListNode`、`TreeNode`、`TreeLinkNode` 与 `RandomListNode` 的定义位于对应题目源码中或题目平台提供的结构定义中。
- 部分题目保留了辅助函数或示例 `main`；表格只列出面向题目的主入口。
