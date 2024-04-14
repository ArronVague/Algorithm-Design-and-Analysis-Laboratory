#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, m;
        cin >> n >> m;
        int s, t;
        cin >> s >> t;
        map<int, map<int, int>> g;
        while (m--)
        {
            int x, y, w;
            cin >> x >> y >> w;
            g[x][y] = w;
            g[y][x] = w;
        }
        double ans = 10000;
        int t_max = 0;
        int t_min = 0;
        function<void(int, int, int, vector<bool>)> dfs = [&](int MAX, int MIN, int cur, vector<bool> vis)
        {
            vis[cur] = true;
            if (cur == t)
            {
                double temp = MAX * 1.0 / MIN;
                if (temp < ans)
                {
                    ans = temp;
                    t_max = MAX;
                    t_min = MIN;
                }
                return;
            }
            for (auto mp : g[cur])
            {
                int nxt = mp.first;
                int wei = mp.second;
                if (!vis[nxt])
                {
                    dfs(max(MAX, wei), min(MIN, wei), nxt, vis);
                }
            }
        };
        vector<bool> vis(n + 1, false);
        dfs(0, 10000, s, vis);
        if (ans == 10000)
        {
            cout << "%%%" << endl;
        }
        else
        {
            if (t_max % t_min == 0)
            {
                cout << ans << endl;
            }
            else
            {
                int fac = gcd(t_max, t_min);
                cout << t_max / fac << "/" << t_min / fac << endl;
            }
        }
    }
}