#include <iostream>
#include <cstring>
using namespace std;

short V, n;
short v[30];
int dp[20001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> V;
    cin >> n;
    for (short i = 0; i < n; ++i)
    {
        cin >> v[i];
    }
    memset(dp, 0, sizeof(dp));
    for (short i = 0; i < n; ++i)
    {
        for (short j = V; j >= v[i]; --j)
        {
            dp[j] = max(dp[j], dp[j - v[i]] + v[i]);
        }
    }
    cout << V - dp[V] << endl;
    return 0;
    //
}