// 线性dp
// 最大子段和
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