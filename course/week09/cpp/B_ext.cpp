#include <iostream>
#include <climits>
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
    // 使用 scanf 和 printf 进行输入输出
    scanf("%d %d %d %d", &s[0], &s[1], &s[2], &s[3]);
    int ans = 0;
    for (int i = 0; i < 4; ++i)
    {
        cur = s[i];
        for (int j = 0; j < cur; ++j)
        {
            scanf("%d", &t[j]);
        }
        res = INT_MAX;
        dfs(0, 0, 0);
        ans += res;
    }
    printf("%d\n", ans);
    return 0;
}