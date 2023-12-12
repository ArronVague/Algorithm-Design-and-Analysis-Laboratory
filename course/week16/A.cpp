#include <bits/stdc++.h>
using namespace std;

int mstKruskal(int n, vector<vector<int>> edges)
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

    int sum = 0;
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
    int N, M;
    cin >> N >> M;
    int X, Y, Z;
    vector<vector<int>> edges;
    while (M--)
    {
        cin >> X >> Y >> Z;
        edges.push_back({X - 1, Y - 1, Z});
    }
    int ans = mstKruskal(N, edges);
    if (ans == -1)
    {
        cout << "orz" << endl;
    }
    else
    {
        cout << ans << endl;
    }
}