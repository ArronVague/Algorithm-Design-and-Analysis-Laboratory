#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int vis[21][21][1 << 10] = {0};
int n, m, t, sx, sy;
char maze[21][21];
int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

struct node
{
    int x, y, key, time;
    node(int x, int y, int key, int time) : x(x), y(y), key(key), time(time) {}
};

int bfs()
{
    queue<node> q;
    q.push(node(sx, sy, 0, 0));
    vis[sx][sy][0] = 1;
    while (!q.empty())
    {
        node tmp = q.front();
        int time = tmp.time;
        if (time >= t)
        {
            return -1;
        }
        q.pop();
        int x = tmp.x, y = tmp.y, key = tmp.key;
        if (maze[x][y] == '^')
        {
            return time;
        }
        // cout << x << " " << y << " " << time << endl;
        for (int i = 0; i < 4; ++i)
        {
            int new_key = 0;
            int nx = x + dir[i][0], ny = y + dir[i][1];
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && maze[nx][ny] != '*')
            {
                if (maze[nx][ny] >= 'a' && maze[nx][ny] <= 'j')
                {
                    new_key |= (1 << (maze[nx][ny] - 'a'));
                }
                else if (maze[nx][ny] >= 'A' && maze[nx][ny] <= 'J')
                {
                    if (!(key & (1 << (maze[nx][ny] - 'A'))))
                    {
                        continue;
                    }
                }
                if (!vis[nx][ny][key])
                {
                    q.push(node(nx, ny, new_key | key, time + 1));
                    vis[nx][ny][key] = 1;
                }
            }
        }
    }
    return -1;
}

int main()
{
    while (cin >> n >> m >> t)
    {
        memset(vis, 0, sizeof(vis));
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
            {
                cin >> maze[i][j];
                if (maze[i][j] == '@')
                {
                    sx = i;
                    sy = j;
                }
            }
        }
        cout << bfs() << endl;
    }
    return 0;
}