#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll> shortestPathSPFA(int n, int st, vector<vector<int>> edges)
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
        // 有向图需要注释掉下面这行
        // g[w].push_back({v, wt});
    }

    const ll inf = (1ll << 31) - 1;
    vector<ll> dist(n, inf);
    dist[st] = 0;
    queue<int> q;
    q.push(st);
    vector<bool> inQ(n);
    inQ[st] = true;
    vector<int> relaxedCnt(n);
    while (q.size())
    {
        int v = q.front();
        q.pop();
        inQ[v] = false;
        for (auto &e : g[v])
        {
            int w = e.to;
            int newD = dist[v] + e.wt;
            if (newD < dist[w])
            {
                dist[w] = newD;
                relaxedCnt[w] = relaxedCnt[v] + 1;
                if (relaxedCnt[w] >= n)
                {
                    return vector<ll>();
                }
                if (!inQ[w])
                {
                    inQ[w] = true;
                    q.push(w);
                }
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
    vector<ll> dist = shortestPathSPFA(n, s - 1, edges);
    for (auto &d : dist)
    {
        cout << d << " ";
    }
    return 0;
}