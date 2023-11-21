#include <bits/stdc++.h>
using namespace std;
/*
kmp
*/

// 计算前缀函数
vector<int> calcPi(string s)
{
    vector<int> pi(s.size());
    for (int i = 1, cnt = 0; i < s.size(); i++)
    {
        int v = s[i];
        while (cnt && s[cnt] != v)
        {
            cnt = pi[cnt - 1];
        }
        if (s[cnt] == v)
        {
            cnt++;
        }
        pi[i] = cnt;
    }
    return pi;
}

// 在 text 中查找 pattern，返回所有成功匹配位置（pattern 首字母的下标）
vector<int> kmpSearch(string text, string pattern)
{
    vector<int> pi = calcPi(pattern);
    int lenP = pattern.size();
    int cnt = 0;
    vector<int> pos;
    for (int i = 0; i < text.size(); i++)
    {
        char v = text[i];
        while (cnt > 0 && pattern[cnt] != v)
        {
            cnt = pi[cnt - 1];
        }
        if (pattern[cnt] == v)
        {
            cnt++;
        }
        if (cnt == lenP)
        {
            pos.push_back(i - lenP + 1);
            cnt = pi[cnt - 1];
        }
    }
    return pos;
}