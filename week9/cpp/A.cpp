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