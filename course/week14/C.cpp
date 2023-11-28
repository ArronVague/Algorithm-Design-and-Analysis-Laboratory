#include <iostream>
#include <vector>
#include <cstring>
#include <functional>
using namespace std;

vector<vector<int>> sccKosaraju(int n, int m)
{
    vector<vector<int>> g(n), rg(n);
    for (int i = 0; i < m; ++i)
    {
        int v, w;
        cin >> v >> w;
        g[v - 1].push_back(w - 1);
        rg[w - 1].push_back(v - 1);
    }

    // 生成 DFS 后序（用于跑逆后序遍历，这样生成的 SCC 一定是拓扑序）
    vector<int> vs;
    vector<bool> vis(n);
    function<void(int)> dfs = [&](int v)
    {
        vis[v] = true;
        for (auto w : g[v])
        {
            if (!vis[w])
            {
                dfs(w);
            }
        }
        vs.push_back(v);
    };
    for (int i = 0; i < n; ++i)
    {
        if (!vis[i])
        {
            dfs(i);
        }
    }

    vis.assign(n, false);
    vector<int> comp;
    function<void(int)> rdfs = [&](int v)
    {
        vis[v] = true;
        comp.push_back(v);
        for (auto w : rg[v])
        {
            if (!vis[w])
            {
                rdfs(w);
            }
        }
    };

    vector<vector<int>> scc;

    for (int i = n - 1; i >= 0; --i)
    {
        int v = vs[i];
        if (!vis[v])
        {
            comp.clear();
            rdfs(v);
            scc.push_back(comp);
        }
    }
    return scc;
}

int N, M;

int main()
{
    while (cin >> N >> M && N)
    {
        auto scc = sccKosaraju(N, M);
        if (scc.size() == 1)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    return 0;
}