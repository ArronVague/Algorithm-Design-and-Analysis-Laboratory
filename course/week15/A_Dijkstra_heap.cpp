#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct dijkstraPair
{
    ll v, dis;
    bool operator<(const dijkstraPair &rhs) const
    {
        return dis > rhs.dis;
    }
};

vector<ll> shortestPathDijkstra(int n, int st, vector<vector<int>> edges)
{
    struct neighbor
    {
        int to, wt;
    };
    vector<vector<neighbor>> g(n, vector<neighbor>());
    for (auto &e : edges)
    {
        int v = e[0], w = e[1], wt = e[2];
        g[v].push_back({w, wt});
        // g[w].push_back({v, wt});
    }

    const ll inf = (1ll << 31) - 1;
    vector<ll> dist(n, inf);
    dist[st] = 0;
    vector<int> from(n, -1);
    priority_queue<dijkstraPair> h;
    h.push({st, 0});
    while (h.size())
    {
        auto p = h.top();
        h.pop();
        int v = p.v;
        if (p.dis > dist[v])
        {
            continue;
        }
        for (auto &e : g[v])
        {
            int w = e.to;
            int newD = dist[v] + e.wt;
            if (newD < dist[w])
            {
                dist[w] = newD;
                from[w] = v;
                h.push({w, dist[w]});
            }
        }
    }
    return dist;
}

int main()
{
    int n, m, s;
    cin >> n >> m >> s;
    vector<vector<int>> edges;
    int u, v, w;
    while (m--)
    {
        cin >> u >> v >> w;
        edges.push_back({u - 1, v - 1, w});
    }
    vector<ll> dis = shortestPathDijkstra(n, s - 1, edges);
    for (auto &d : dis)
    {
        cout << d << " ";
    }
    return 0;
}