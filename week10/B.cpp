#include <iostream>
#include <queue>
#include <string>
using namespace std;

int vis[362888] = {0};
int fac[10] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
char dir_c[4] = {'l', 'r', 'u', 'd'};

int Cantor(string s)
{
    int res = 0;
    for (int i = 0; i < 9; ++i)
    {
        int cnt = 0;
        for (int j = i + 1; j < 9; ++j)
        {
            if (s[i] > s[j])
            {
                cnt++;
            }
        }
        res += cnt * fac[9 - i - 1];
    }
    return res;
}

struct node
{
    string state;
    int cantor;
    int pos;
    node(string s, int c, int p) : state(s), cantor(c), pos(p) {}
};

struct path
{
    int from;
    char d;
} pa[362888];

void bfs(string s)
{
    queue<node> q;
    int can = Cantor(s);
    q.push(node(s, can, 8));
    vis[can] = 1;
    pa[can].from = -1;
    while (!q.empty())
    {
        // cout << "yes" << endl;
        node t = q.front();
        q.pop();
        int x = t.pos / 3, y = t.pos % 3;
        for (int i = 0; i < 4; ++i)
        {
            int nx = x + dir[i][0], ny = y + dir[i][1];
            if (nx >= 0 && nx < 3 && ny >= 0 && ny < 3)
            {
                string tmp = t.state;
                int nxt_s = nx * 3 + ny;
                swap(tmp[t.pos], tmp[nxt_s]);
                can = Cantor(tmp);
                if (!vis[can])
                {
                    vis[can] = 1;
                    // cout << can << " " << t.cantor << endl;
                    pa[can].from = t.cantor;
                    pa[can].d = dir_c[i];
                    q.push(node(tmp, can, nxt_s));
                }
            }
        }
    }
}

int main()
{
    bfs("12345678x");
    string s;
    while (getline(cin, s))
    {
        string puzzle;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] != ' ')
            {
                puzzle += s[i];
            }
        }
        int can = Cantor(puzzle);
        if (vis[can])
        {
            while (can != -1)
            {
                cout << pa[can].d;
                can = pa[can].from;
            }
            cout << endl;
        }
        else
        {
            cout << "unsolvable" << endl;
        }
    }
    return 0;
}