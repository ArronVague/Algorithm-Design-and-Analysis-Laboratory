#include <iostream>
#include <cstring>
using namespace std;

int n;
int vis[10];

void dfs(string s, int cnt)
{
    if (cnt == n)
    {
        for (char c : s)
        {
            cout << c << " ";
        }
        cout << endl;
        return;
    }
    for (int i = 1; i <= n; ++i)
    {
        if (!vis[i])
        {
            vis[i] = 1;
            dfs(s + to_string(i), cnt + 1);
            vis[i] = 0;
        }
    }
}

int main()
{
    cin >> n;
    memset(vis, 0, sizeof(vis));
    dfs("", 0);
    return 0;
}