#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        vector<int> num;
        int n = 6;
        int a;
        while (n--)
        {
            cin >> a;
            num.push_back(a);
        }
        int ans = 0;
        for (int i = 0; i < 3; ++i)
        {
            if (num[i] == num[i + 3])
            {
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}