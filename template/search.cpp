// 网格图 BFS
// https://vjudge.net/contest/589743#problem/A
// https://vjudge.net/contest/589743#problem/C

#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int W, H;
char g[20][20];
int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int main()
{
    while (cin >> W >> H)
    {
        if (W == 0 && H == 0)
        {
            break;
        }
        int cx, cy;
        for (int i = 0; i < H; ++i)
        {
            for (int j = 0; j < W; ++j)
            {
                cin >> g[i][j];
                if (g[i][j] == '@')
                {
                    cx = i;
                    cy = j;
                }
            }
        }
        queue<pair<int, int>> q;
        q.push(make_pair(cx, cy));
        g[cx][cy] = '#';
        int ans = 1;
        while (!q.empty())
        {
            cx = q.front().first;
            cy = q.front().second;
            q.pop();
            for (int i = 0; i < 4; ++i)
            {
                int nx = cx + d[i][0];
                int ny = cy + d[i][1];
                if (nx >= 0 && nx < H && ny >= 0 && ny < W && g[nx][ny] == '.')
                {
                    q.push(make_pair(nx, ny));
                    g[nx][ny] = '#';
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}

// 迭代加深搜索
// 限制 DFS 深度（不断提高搜索深度）
// https://vjudge.net/contest/589743#problem/B
#include <iostream>
using namespace std;

int s[4];
int t[20];
int res;
int cur;

void dfs(int l, int r, int j)
{
    if (j >= cur)
    {
        res = min(res, max(l, r));
        return;
    }
    dfs(l + t[j], r, j + 1);
    dfs(l, r + t[j], j + 1);
}

int main()
{
    cin >> s[0] >> s[1] >> s[2] >> s[3];
    int ans = 0;

    for (int i = 0; i < 4; ++i)
    {
        cur = s[i];
        for (int j = 0; j < cur; ++j)
        {
            cin >> t[j];
        }
        res = 1200;
        dfs(0, 0, 0);
        ans += res;
    }
    cout << ans << endl;
    return 0;
}