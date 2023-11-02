#include <iostream>
using namespace std;

int T;
int arr[100001];

int main()
{
    cin >> T;
    int cnt = 1;
    while (T--)
    {
        int n;
        cin >> n;
        for (int i = 1; i <= n; ++i)
        {
            cin >> arr[i];
        }
        int res = 0;
        int left = 1;
        int max_res = INT_MIN;
        // cout << max_res << endl;
        int max_left = 1;
        int max_right = 1;
        for (int i = 1; i <= n; ++i)
        {
            res += arr[i];
            if (res > max_res)
            {
                max_res = res;
                max_left = left;
                max_right = i;
            }
            if (res < 0)
            {
                res = 0;
                left = i + 1;
            }
        }
        cout << "Case " << cnt++ << ":" << endl;
        cout << max_res << " " << max_left << " " << max_right << endl;
        if (T)
        {
            cout << endl;
        }
    }
    return 0;
}