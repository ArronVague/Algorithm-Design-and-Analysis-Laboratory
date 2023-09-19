#include <bits/stdc++.h>
using namespace std;

int t, n;
string s;

int main()
{
    cin >> t;

    while (t--)
    {
        cin >> n >> s;
        function<int(int, int, char)> dfs = [&](int left, int right, char c) -> int
        {
            if (left == right)
            {
                return s[left] != c;
            }
            int mid = left + (right - left) / 2;
            int l_res = 0;
            int r_res = 0;
            for (int i = left; i <= mid; ++i)
            {
                l_res += s[i] != c;
            }
            for (int i = mid + 1; i <= right; ++i)
            {
                r_res += s[i] != c;
            }
            return min(l_res + dfs(mid + 1, right, c + 1), r_res + dfs(left, mid, c + 1));
        };
        cout << dfs(0, n - 1, 'a') << endl;
    }
    return 0;
}