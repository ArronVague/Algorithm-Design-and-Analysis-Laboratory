#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

int n, r;

int main()
{
    cin >> n >> r;
    vector<vector<int>> ans;
    for (int i = 0; i < (1 << n); ++i)
    {
        int cnt = 0;
        for (int j = 0; j < n; ++j)
        {
            if (i >> j & 1)
            {
                cnt++;
            }
        }
        if (cnt == r)
        {
            vector<int> t;
            for (int j = 0; j < n; ++j)
            {
                if (i >> j & 1)
                {
                    t.push_back(j + 1);
                }
            }
            ans.push_back(t);
        }
    }
    sort(ans.begin(), ans.end(), [&](const auto &a, const auto &b)
         {
            for (int i = 0; i < a.size(); ++i) {
                if (a[i] != b[i]) {
                    return a[i] < b[i];
                }
            }
            return a[0] < b[0]; });
    for (auto &t : ans)
    {
        for (auto &x : t)
        {
            cout << setw(3) << x;
        }
        cout << endl;
    }
    return 0;
}