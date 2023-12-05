#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll> shortestPathDijkstra2(vector<vector<pair<int, int>>> g, int st)
{
    int n = g.size();

    const ll inf = (1ll << 31) - 1;
    vector<ll> dis(n, inf);
    dis[st] = 0;
    vector<bool> vis(n);
    while (true)
    {
        int v = -1;
        for (int w = 0; w < vis.size(); ++w)
        {
            bool b = vis[w];
            if (!b && (v < 0 || dis[w] < dis[v]))
            {
                v = w;
            }
        }
        if (v < 0)
        {
            return dis;
        }
        vis[v] = true;
        for (auto &e : g[v])
        {
            int w = e.first, d = e.second;
            dis[w] = min(dis[w], dis[v] + d);
        }
    }
}

int main()
{
    int n, m, s;
    cin >> n >> m >> s;
    vector<vector<pair<int, int>>> g(n, vector<pair<int, int>>());
    int u, v, w;
    while (m--)
    {
        cin >> u >> v >> w;
        g[u - 1].push_back({v - 1, w});
    }
    vector<ll> dis = shortestPathDijkstra2(g, s - 1);
    for (auto &d : dis)
    {
        cout << d << " ";
    }
    return 0;
}