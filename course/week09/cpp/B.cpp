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