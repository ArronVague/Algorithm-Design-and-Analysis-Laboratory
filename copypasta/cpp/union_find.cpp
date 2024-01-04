#include <bits/stdc++.h>
using namespace std;

/*
并查集
*/

class UnionFind
{
private:
    vector<int> Fa;
    int Groups;

public:
    UnionFind(int n)
    {
        Fa.resize(n + 1);
        for (int i = 1; i <= n; i++)
            Fa[i] = i;
    }

    // 递归写法
    int find(int x)
    {
        return x == Fa[x] ? x : Fa[x] = find(Fa[x]);
    }

    int merge(int x, int y)
    {
        int fx = find(x), fy = find(y);
        if (fx == fy)
            return -1;
        Fa[fx] = fy;
        Groups--;
        return fy;
    }
};
