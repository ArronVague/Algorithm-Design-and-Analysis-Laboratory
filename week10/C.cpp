#include <iostream>
#include <queue>
using namespace std;

int step[41][41] = {0};
int vis[41][41] = {0};

int R, C;
char maze[41][41];
int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int dbfs()
{
    queue<pair<int, int>> q[2];
    q[0].push(make_pair(1, 1));
    q[1].push(make_pair(R, C));
    vis[1][1] = 1;
    vis[R][C] = 2;
    step[1][1] = 1;
    step[R][C] = 1;
    while (!q[0].empty() && !q[1].empty())
    {
        // for (int r = 1; r <= R; ++r)
        // {
        //     for (int c = 1; c <= C; ++c)
        //     {
        //         cout << step[r][c];
        //     }
        //     cout << endl;
        // }
        // cout << endl;

        // for (int r = 1; r <= R; ++r)
        // {
        //     for (int c = 1; c <= C; ++c)
        //     {
        //         cout << vis[r][c];
        //     }
        //     cout << endl;
        // }
        // cout << endl;
        int i = q[0].size() < q[1].size() ? 0 : 1;
        pair<int, int> t = q[i].front();
        q[i].pop();
        int x = t.first, y = t.second;
        for (int j = 0; j < 4; ++j)
        {
            int nx = x + dir[j][0], ny = y + dir[j][1];
            if (nx >= 1 && nx <= R && ny >= 1 && ny <= C && maze[nx][ny] != '#')
            {
                if (!vis[nx][ny])
                {
                    vis[nx][ny] = vis[x][y];
                    step[nx][ny] = step[x][y] + 1;
                    q[i].push(make_pair(nx, ny));
                }
                else if (vis[nx][ny] + vis[x][y] == 3)
                {
                    return step[nx][ny] + step[x][y];
                }
            }
        }
    }
    return -1;
}

int main()
{
    cin >> R >> C;
    for (int i = 1; i <= R; ++i)
    {
        for (int j = 1; j <= C; ++j)
        {
            cin >> maze[i][j];
        }
    }
    cout << dbfs() << endl;
    return 0;
}