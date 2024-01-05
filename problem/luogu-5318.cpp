#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n + 1, vector<int>());
    int X, Y;
    while (m--)
    {
        cin >> X >> Y;
        a[X].push_back(Y);
    }
    for (int i = 1; i <= n; ++i)
    {
        sort(a[i].begin(), a[i].end());
    }
    vector<bool> vis(n + 1, false);
    function<void(int)> dfs = [&](int x)
    {
        cout << x << " ";
        vis[x] = true;
        for (int i = 0; i < a[x].size(); ++i)
        {
            if (!vis[a[x][i]])
            {
                dfs(a[x][i]);
            }
        }
    };
    dfs(1);

    cout << endl;

    queue<int> q;
    q.push(1);
    vis[1] = false;
    // bfs
    while (q.size())
    {
        int t = q.front();
        q.pop();
        cout << t << " ";
        for (int i = 0; i < a[t].size(); ++i)
        {
            if (vis[a[t][i]])
            {
                vis[a[t][i]] = false;
                q.push(a[t][i]);
            }
        }
    }
    return 0;
}