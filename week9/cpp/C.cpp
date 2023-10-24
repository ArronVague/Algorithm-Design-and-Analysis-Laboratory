#include <bits/stdc++.h>
using namespace std;

int ans[401][401];
int n, m, x, y;
int d[8][2] = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};

int main()
{
    cin >> n >> m >> x >> y;
    memset(ans, -1, sizeof(ans));
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    ans[x][y] = 0;
    while (!q.empty())
    {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for (int i = 0; i < 8; ++i)
        {
            int nx = x + d[i][0];
            int ny = y + d[i][1];
            if (nx > 0 && nx <= n && ny > 0 && ny <= m && ans[nx][ny] == -1)
            {
                q.push(make_pair(nx, ny));
                ans[nx][ny] = ans[x][y] + 1;
            }
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}