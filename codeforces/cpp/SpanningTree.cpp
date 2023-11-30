#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll mstKruskal(int n, vector<vector<int>> &edges)
{
    sort(edges.begin(), edges.end(), [](const vector<int> &a, const vector<int> &b)
         { return a[2] < b[2]; });

    vector<int> fa(n);
    for (int i = 0; i < fa.size(); ++i)
    {
        fa[i] = i;
    }
    function<int(int)> find = [&](int x)
    {
        return fa[x] == x ? x : fa[x] = find(fa[x]);
    };

    ll sum = 0;
    int cntE = 0;
    for (auto &e : edges)
    {
        int v = e[0], w = e[1], wt = e[2];
        int fv = find(v), fw = find(w);
        if (fv != fw)
        {
            fa[fv] = fw;
            sum += wt;
            cntE++;
        }
    }

    if (cntE < n - 1)
    {
        return -1;
    }
    return sum;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    vector<vector<int>> edges;
    int u, v, w;
    while (M--)
    {
        cin >> u >> v >> w;
        edges.push_back({u - 1, v - 1, w});
    }
    ll ans = mstKruskal(N, edges);
    cout << ans;
    return 0;
}