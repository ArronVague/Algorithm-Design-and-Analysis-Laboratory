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
    cout << ans << endl;
    return 0;
}
