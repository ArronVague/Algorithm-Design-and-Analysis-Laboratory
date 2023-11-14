#include <iostream>
using namespace std;
#define ll long long

int main()
{
    ll l, r, k, ans;
    while (cin >> l >> r >> k)
    {
        ans = 1;
        bool flag = false;
        while (1)
        {

            if (ans >= l && ans <= r)
            {
                flag = true;
                cout << ans << " ";
            }
            if (ans > r / k)
            {
                break;
            }
            ans *= k;
        }
        if (!flag)
        {
            cout << -1 << endl;
        }
    }
}