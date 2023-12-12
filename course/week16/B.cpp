#include <bits/stdc++.h>
using namespace std;

int ans;

vector<int> maxBipartiteMatchingHungarian(vector<vector<int>> &g)
{
    int n = g.size();
    vector<int> match(n, -1);
    vector<int> vis(n, -1);
    int cnt = 0;

    for (int root = 0; root < n; ++root)
    {
        if (match[root] != -1)
        {
            continue;
        }

        function<bool(int)> dfs = [&](int v) -> bool
        {
            vis[v] = root;
            for (int w : g[v])
            {
                int mw = match[w];
                if (mw == -1 || (vis[mw] != root && dfs(mw)))
                {
                    match[w] = v;
                    match[v] = w;
                    return true;
                }
            }
            return false;
        };
        // function<bool(int)> dfs = [&](int v) -> bool
        // {
        //     vis[v] = root;
        //     for (int w : g[v])
        //     {
        //         int mw = match[w];
        //         if (mw == -1 || (vis[mw] != root && dfs(mw)))
        //         {
        //             match[w] = v;
        //             match[v] = w;
        //             return true;
        //         }
        //     }
        //     return false;
        // };

        if (dfs(root))
        {
            cnt++;
        }
    }
    ans = cnt;
    return match;
}

int main()
{
    int n, m, e;
    cin >> n >> m >> e;
    int u, v;
    vector<vector<int>> g(n + m);
    while (e--)
    {
        cin >> u >> v;
        g[u - 1].push_back(v - 1 + n);
        g[v - 1 + n].push_back(u - 1);
    }
    maxBipartiteMatchingHungarian(g);
    cout << ans << endl;
}