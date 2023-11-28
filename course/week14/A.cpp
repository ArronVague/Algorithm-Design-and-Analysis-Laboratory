#include <iostream>
#include <queue>
#include <vector>
#include <functional>
using namespace std;

const int maxN = 510;

vector<int> topoSort(int n, vector<vector<int>> edges)
{
    vector<vector<int>> g(n);
    vector<int> deg(n);
    for (auto &e : edges)
    {
        int v = e[0], w = e[1];
        g[v].push_back(w);
        deg[w]++;
    }

    priority_queue<int, vector<int>, greater<int>> q;
    vector<int> orders;
    for (int i = 0; i < n; ++i)
    {
        if (deg[i] == 0)
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int x = q.top();
        q.pop();
        orders.push_back(x);
        for (auto y : g[x])
        {
            if (--deg[y] == 0)
            {
                q.push(y);
            }
        }
    }
    return orders;
}

int main()
{
    int N, M;
    while (cin >> N >> M)
    {
        vector<vector<int>> edges;
        int u, v;
        while (M--)
        {
            cin >> u >> v;
            edges.push_back({u - 1, v - 1});
        }
        vector<int> ans = topoSort(N, edges);
        cout << ans[0] + 1;
        for (int i = 1; i < ans.size(); i++)
            cout << " " << ans[i] + 1;
    }
    return 0;
}