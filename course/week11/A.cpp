#include <bits/stdc++.h>
using namespace std;

const int maxN = 5001;
int fa[maxN];
int n, m, p;
int i, j;

void init()
{
    for (int i = 1; i <= maxN; i++)
        fa[i] = i;
}

int find(int x)
{
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

void merge(int x, int y)
{
    fa[find(x)] = find(y);
}

int main()
{
    cin >> n >> m >> p;
    init();
    while (m--)
    {
        cin >> i >> j;
        merge(i, j);
    }
    while (p--)
    {
        cin >> i >> j;
        if (find(i) == find(j))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}