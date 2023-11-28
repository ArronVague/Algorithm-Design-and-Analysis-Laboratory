#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 10;
int n, m;
int indeg[MAXN], outdeg[MAXN];
vector<int> g[MAXN];
int u, v;
vector<int> ans;
int flag[MAXN];

vector<int> eulerianPathOnDirectedGraph(int n, int m)
{
    vector<vector<int>> g(n, vector<int>());
    vector<int> inDeg(n);

    for (int i = 0; i < m; ++i)
    {
        int v, w;
        cin >> v >> w;
        g[v - 1].push_back(w - 1);
        inDeg[w - 1]++;
    }

    // 排序，保证字典序最小
    for (auto &es : g)
    {
        sort(es.begin(), es.end());
    }

    int st = -1, end = -1;
    for (int i = 0; i < g.size(); ++i)
    {
        // 出度比入度大一，为起点
        if (g[i].size() == inDeg[i] + 1)
        {
            if (st >= 0)
            {
                return vector<int>();
            }
            st = i;
        }
        // 入度比出度大一，为终点
        if (g[i].size() + 1 == inDeg[i])
        {
            if (end >= 0)
            {
                return vector<int>();
            }
            else
            {
                end = i;
            }
        }
        // 任意起点
        if (st < 0)
        {
            st = 0;
        }
    }
    vector<int> path(m + 1);
    function<void(int)> dfs = [&](int u)
    {
        while (g[u].size())
        {
            int v = g[u].front();
            g[u].erase(g[u].begin());
            dfs(v);
        }
        path.push_back(u + 1);
    };
    dfs(st);
    cout << ans.size() << endl;
    reverse(path.begin(), path.end());
    return path;
}

int main()
{
    cin >> n >> m;
    vector<int> ans = eulerianPathOnDirectedGraph(n, m);
    if (ans.size() == 0)
    {
        cout << "NO" << endl;
    }
    else
    {

        for (auto i : ans)
        {
            cout << i << " ";
        }
    }
    return 0;
}