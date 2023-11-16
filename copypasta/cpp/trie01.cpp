/*
异或字典树
*/
// https://leetcode.cn/problems/maximum-strong-pair-xor-ii/description/ 找出强数对的最大异或值 II
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    array<Node *, 2> children{};
    int cnt = 0; // 子树大小
};

class Trie
{
    static const int HIGH_BIT = 19;

public:
    Node *root = new Node();

    // 添加 val
    void insert(int val)
    {
        Node *cur = root;
        for (int i = HIGH_BIT; i >= 0; i--)
        {
            int bit = (val >> i) & 1;
            if (cur->children[bit] == nullptr)
            {
                cur->children[bit] = new Node();
            }
            cur = cur->children[bit];
            cur->cnt++; // 维护子树大小
        }
    }

    // 删除 val，但不删除节点
    // 要求 val 必须在 trie 中
    void remove(int val)
    {
        Node *cur = root;
        for (int i = HIGH_BIT; i >= 0; i--)
        {
            cur = cur->children[(val >> i) & 1];
            cur->cnt--; // 维护子树大小
        }
    }

    // 返回 val 与 trie 中一个元素的最大异或和
    // 要求 trie 不能为空
    // 视题目要求写
    int max_xor(int val)
    {
        Node *cur = root;
        int ans = 0;
        for (int i = HIGH_BIT; i >= 0; i--)
        {
            int bit = (val >> i) & 1;
            // 如果 cur.children[bit^1].cnt == 0，视作空节点
            if (cur->children[bit ^ 1] && cur->children[bit ^ 1]->cnt)
            {
                ans |= 1 << i;
                bit ^= 1;
            }
            cur = cur->children[bit];
        }
        return ans;
    }
};