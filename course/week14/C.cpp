#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int maxN = 1e4 + 10;

vector<vector<int>> g(maxN), rg(maxN);
bool vis[maxN];
int L[maxN];
int N, M;
int k;

void init()
{
    k = 0;
    for (int i = 0; i <= N; i++)
    {
        g[i].clear();
        rg[i].clear();
    }
    memset(vis, 0, sizeof(vis));
    memset(L, 0, sizeof(L));
}

void dfs1(int x)
{
    vis[x] = true;
    // cout << "?" << endl;
    for (int i = 0; i < rg[x].size(); i++)
    {
        if (vis[rg[x][i]] == false)
        {
            dfs1(rg[x][i]);
        }
    }
    L[++k] = x;
}

void dfs2(int x)
{
    vis[x] = false;
    for (int i = 0; i < g[x].size(); i++)
    {
        if (vis[g[x][i]])
        {
            dfs2(g[x][i]);
        }
    }
}

int main()
{
    while (cin >> N >> M && N)
    {
        init();
        int a, b;
        while (M--)
        {
            cin >> a >> b;
            g[a].push_back(b);
            rg[b].push_back(a);
        }
        // cout << "yes" << endl;
        for (int i = 1; i <= N; i++)
        {
            if (vis[i] == false)
            {
                dfs1(i);
            }
        }
        int cnt = 0;
        for (int i = N; i >= 1; i--)
        {
            if (vis[L[i]] == true)
            {
                cnt++;
                dfs2(L[i]);
            }
        }
        if (cnt > 1)
        {
            cout << "No" << endl;
        }
        else
        {
            cout << "Yes" << endl;
        }
    }
    return 0;
}