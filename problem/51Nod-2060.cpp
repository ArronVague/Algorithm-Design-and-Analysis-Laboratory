#include <iostream>
#include <cstring>
#include <functional>
using namespace std;

int n;
int vis[10];

// void dfs(string s, int cnt)
// {
//     if (cnt == n)
//     {
//         for (char c : s)
//         {
//             cout << c << " ";
//         }
//         cout << endl;
//         return;
//     }
//     for (int i = 1; i <= n; ++i)
//     {
//         if (!vis[i])
//         {
//             vis[i] = 1;
//             dfs(s + to_string(i), cnt + 1);
//             vis[i] = 0;
//         }
//     }
// }

int main()
{
    cin >> n;
    memset(vis, 0, sizeof(vis));
    function<void(string)> dfs = [&](string s)
    {
        if (s.size() == n)
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
                dfs(s + to_string(i));
                vis[i] = 0;
            }
        }
    };
    dfs("");
    return 0;
}