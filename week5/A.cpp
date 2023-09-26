#include <bits/stdc++.h>
using namespace std;

int n;

int main()
{
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; ++i)
    {
        int t;
        cin >> t;
        pq.push(t);
    }
    int ans = 0;
    while (pq.size() > 1)
    {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        // cout << a << " " << b << endl;
        ans += a + b;
        pq.push(a + b);
    }
    cout << ans << endl;
    return 0;
}