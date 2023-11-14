#include <bits/stdc++.h>
using namespace std;

string a, b;
int mod = 1e8;
int dp[2][5001];
int num[2][5001];

int main()
{
    cin >> a >> b;
    int n = a.size() - 1;
    int m = b.size() - 1;
    // 耗时太大
    // vector<vector<int>> dp(2, vector<int>(m + 1, 0));
    // vector<vector<int>> num(2, vector<int>(m + 1, 1));
    for (int i = 0; i < m; ++i)
    {
        cout << dp[0][m];
        num[0][i] = 1;
    }
    num[1][0] = 1;
    int t = 0;
    for (int i = 1; i <= n; ++i, t ^= 1)
    {
        for (int j = 1; j <= m; ++j)
        {
            num[t ^ 1][j] = 0;
            if (a[i - 1] == b[j - 1])
            {
                dp[t ^ 1][j] = dp[t][j - 1] + 1;
                num[t ^ 1][j] += num[t][j - 1] % mod;
            }
            else
            {
                dp[t ^ 1][j] = max(dp[t][j], dp[t ^ 1][j - 1]);
            }
            if (dp[t ^ 1][j] == dp[t][j])
            {
                num[t ^ 1][j] += num[t][j] % mod;
            }
            if (dp[t ^ 1][j] == dp[t ^ 1][j - 1])
            {
                num[t ^ 1][j] += num[t ^ 1][j - 1] % mod;
            }
            if (a[i - 1] != b[j - 1] && dp[t ^ 1][j] == dp[t][j - 1])
            {
                num[t ^ 1][j] -= num[t][j - 1];
            }
        }
    }
    cout << dp[t][m] << endl;
    cout << num[t][m] << endl;
}