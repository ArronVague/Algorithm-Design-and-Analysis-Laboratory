#include <bits/stdc++.h>
using namespace std;

int k, x, y;
int g[1000][1000];
int cnt;

int main()
{
    cin >> k >> x >> y;
    g[x][y] = 0;
    cnt = 1;
    function<void(int, int, int, int, int)> dfs = [&](int cx, int cy, int x, int y, int size) -> void
    {
        if (size == 1)
        {
            return;
        }
        int t = cnt++;
        int mid = size / 2;
        // ne
        int spe_x = cx + mid - 1;
        int spe_y = cy + mid - 1;
        if (x <= spe_x && y <= spe_y)
        {
            dfs(cx, cy, x, y, mid);
        }
        else
        {
            g[spe_x][spe_y] = t;
            dfs(cx, cy, spe_x, spe_y, mid);
        }

        if (x <= spe_x && y > spe_y)
        {
            dfs(cx, cy + mid, x, y, mid);
        }
        else
        {
            g[spe_x][spe_y + 1] = t;
            dfs(cx, cy + mid, spe_x, spe_y + 1, mid);
        }
        if (x > spe_x && y <= spe_y)
        {
            dfs(cx + mid, cy, x, y, mid);
        }
        else
        {
            g[spe_x + 1][spe_y] = t;
            dfs(cx + mid, cy, spe_x + 1, spe_y, mid);
        }
        if (x > spe_x && y > spe_y)
        {
            dfs(cx + mid, cy + mid, x, y, mid);
        }
        else
        {
            g[spe_x + 1][spe_y + 1] = t;
            dfs(cx + mid, cy + mid, spe_x + 1, spe_y + 1, mid);
        }
    };
    dfs(1, 1, x, y, 1 << k);
    for (int i = 1; i <= 1 << k; ++i)
    {
        for (int j = 1; j <= 1 << k; ++j)
        {
            cout << g[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}