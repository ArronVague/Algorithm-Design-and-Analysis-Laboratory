#include <iostream>
#include <vector>
using namespace std;
#define ll long long

int N;

int main()
{
    int cnt = 0;
    while (cin >> N)
    {
        cnt++;
        vector<int> a(N);
        for (int i = 0; i < N; ++i)
        {
            cin >> a[i];
        }
        ll ans = 0;
        for (int i = 0; i < N; ++i)
        {
            ll res = 1;
            for (int j = i; j < N; ++j)
            {
                res *= a[j];
                ans = max(ans, res);
            }
        }
        cout << "Case #" << cnt << ": The maximum product is " << ans << "." << endl;
        cout << endl;
    }
    return 0;
}