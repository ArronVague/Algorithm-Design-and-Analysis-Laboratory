/*
并查集
*/

#include <bits/stdc++.h>
using namespace std;

class UnionFind
{
private:
    vector<int> fa;

public:
    UnionFind(int n)
    {
        fa.resize(n + 1);
        for (int i = 1; i <= n; i++)
            fa[i] = i;
    }

    // 递归写法
    int find(int x)
    {
        return x == fa[x] ? x : fa[x] = find(fa[x]);
    }

    int merge(int x, int y)
    {
        int fx = find(x), fy = find(y);
        if (fx == fy)
            return -1;
        fa[fx] = fy;
        return fy;
    }
};
