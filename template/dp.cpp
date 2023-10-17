// 背包
//   0-1背包
// https://vjudge.net/contest/586721#problem/B 采药
// https://vjudge.net/contest/586721#problem/C 装箱问题

#include <bits/stdc++.h>
using namespace std;

int T, M;
int t[101];
int price[101];

int main()
{
    cin >> T >> M;
    for (int i = 1; i <= M; ++i)
    {
        cin >> t[i] >> price[i];
    }
    vector<vector<int>> dp(M + 1, vector<int>(T + 1, 0));
    for (int i = 1; i <= M; ++i)
    {
        for (int j = 1; j <= T; ++j)
        {
            if (j < t[i])
                dp[i][j] = dp[i - 1][j];
            else
            {
                // 关键：状态转移方程
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - t[i]] + price[i]);
            }
        }
    }
    cout << dp[M][T] << endl;
    return 0;
}

// 线性dp
//   最大子段和
// https://vjudge.net/contest/581855#problem/E
// https://leetcode.cn/problems/maximum-subarray/description/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n;
int a[200000];

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    ll ans = LLONG_MIN;
    ll res = 0;
    for (int i = 0; i < n; ++i)
    {
        res = max(res, 0ll) + a[i];
        ans = max(ans, res);
    }
    cout << ans;
    return 0;
}

// 相似题
// https://vjudge.net/contest/581855#problem/B

//  LCS（最长公共子序列）
// 模板题：https://vjudge.net/contest/588279#problem/B
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    string a, b;
    while (cin >> a >> b)
    {
        int n = a.size();
        int m = b.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
            {
                if (a[i - 1] == b[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        cout << dp[n][m] << endl;
    }
}