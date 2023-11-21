#include <bits/stdc++.h>
using namespace std;

/*
前缀树/字典树/单词查找树
*/
// https://leetcode.cn/problems/maximum-strong-pair-xor-ii/description/ 找出强数对的最大异或值 II

class trieNode
{
public:
    trieNode *son[26];
    int cnt = 0; // （子树中）完整字符串的个数
    int val;

    bool isEnd;

    bool empty(trieNode *o)
    {
        for (auto son : o->son)
        {
            if (son != NULL)
            {
                return false;
            }
        }
        return true;
    }
};

class trie
{
public:
    trieNode *root = new trieNode();

    trieNode *put(string s, int val)
    {
        trieNode *o = root;
        for (auto b : s)
        {
            int i = b - 'a';
            if (o->son[i] == NULL)
            {
                o->son[i] = new trieNode();
            }
            o = o->son[i];
            // o->cnt++; // 写法一：统计o对应的字符串是多少个完整字符串的前缀
        }
        o->cnt++; // 写法二：统计o上有多少个完整字符串
        o->val = val;
        return o;
    }

    trieNode *find(string s)
    {
        trieNode *o = root;
        for (auto b : s)
        {
            o = o->son[b - 'a'];
            // 未找到s，且s不是任何字符串的前缀
            if (o == NULL)
            {
                return NULL;
            }
        }
        // 未找到 s，但是 s 是某个字符串的前缀
        if (o->cnt == 0) // 已删除
        {
            return NULL;
        }
        return o;
    }

    // 返回 trie 中前缀为 p 的字符串个数
    // 此时 o.cnt 保存子树字符串个数
    int countStringHasPrefix(string p)
    {
        trieNode *o = root;
        for (auto b : p)
        {
            o = o->son[b - 'a'];
            if (o == NULL)
            {
                return 0;
            }
        }
        return o->cnt;
    }
};
