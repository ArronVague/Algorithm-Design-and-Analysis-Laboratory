#include <bits/stdc++.h>
using namespace std;

/*
树状数组（Fenwick Tree），二叉索引树（Binary Index Tree, BIT）
https://en.wikipedia.org/wiki/Fenwick_tree
原论文 https://doi.org/10.1002/spe.4380240306
树状数组 tree 的基本用途是维护序列 a 的前缀和（tree 和 a 的下标都从 1 开始）
tree[i] = a[i-lowbit(i)+1] + ... + a[i]
看图 https://oi-wiki.org/ds/fenwick/
更新 a[i] 的时候，会首先更新最下面的包含 a[i] 的 tree[i]，然后逐渐往上，更新包含这个元素的 tree[i]
这些节点（下标）都在 i 后面，所以更新的时候是从小往大算
计算某个前缀的时候，需要拆分区间，先把最右边的 arr[i-lowbit(i)+1] + ... + arr[i] 算出来，然后再去掉 i 最低位，算下一个区间
所以计算前缀是从大往小算
这里从小往大和从大往小说的是 i 的变化

可视化 https://visualgo.net/zh/fenwicktree
by 灵茶山艾府
*/
// 模板题：区域和检索 - 数组可修改 https://leetcode.cn/problems/range-sum-query-mutable/description/
// 练习
// 315. 计算右侧小于当前元素的个数 https://leetcode.cn/problems/count-of-smaller-numbers-after-self/description/
// 493. 翻转对 https://leetcode.cn/problems/reverse-pairs/description/
// 327. 区间和的个数 https://leetcode.cn/problems/count-of-range-sum/description/
// 2426. 满足不等式的数对数目 https://leetcode.cn/problems/number-of-pairs-satisfying-inequality/description/
class FenwickTree
{
private:
    vector<int> nums;
    vector<int> tree;

    int prefixSum(int i)
    {
        int s = 0;
        for (; i > 0; i &= i - 1)
        { // i -= i & -i 的另一种写法
            s += tree[i];
        }
        return s;
    }

public:
    FenwickTree(vector<int> &nums) : nums(nums.size()), tree(nums.size() + 1)
    {
        // nums的下标从0/1开始都行，但是tree的下标无论如何都是1开始
        for (int i = 0; i < nums.size(); i++)
        {
            update(i, nums[i]);
        }
    }

    // 传入的index是nums的下标，从0开始
    void update(int index, int val)
    {
        int delta = val - nums[index];
        nums[index] = val;
        // nums下标从0开始，因此index要加1
        for (int i = index + 1; i < tree.size(); i += i & -i)
        {
            tree[i] += delta;
        }
    }

    // 传入的参数是nums的下标，从0开始
    int sumRange(int left, int right)
    {
        // prefixSum的参数是tree的下标，从1开始，因此要加1
        return prefixSum(right + 1) - prefixSum(left);
    }
};