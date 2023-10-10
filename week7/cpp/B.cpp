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
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - t[i]] + price[i]);
            }
        }
    }
    cout << dp[M][T] << endl;
    return 0;
}