#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int n, m;
    cin >> n >> m;
    vector<vector<int>> maze(n, vector<int>(m));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> maze[i][j];
        }
    }
    int sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;
    queue<pair<int, int>> q;
    q.push(make_pair(sx - 1, sy - 1));
    tx--;
    ty--;
    maze[0][0] = 1;
    int ans = 0;
    bool flag = false;
    while (q.size())
    {
        int len = q.size();
        while (len--)
        {
            auto t = q.front();
            q.pop();
            int cx = t.first, cy = t.second;
            // cout << cx << " " << cy << endl;
            if (cx == tx && cy == ty)
            {
                flag = true;
                cout << ans;
                break;
            }
            for (int i = 0; i < 4; ++i)
            {
                int nx = cx + dir[i][0];
                int ny = cy + dir[i][1];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m || maze[nx][ny] == 1)
                {
                    continue;
                }
                q.push(make_pair(nx, ny));
                maze[nx][ny] = 1;
            }
        }
        ans++;
    }
    if (!flag)
    {
        cout << "No";
    }
    return 0;
}