#include <bits/stdc++.h>
using namespace std;

int n;

int main()
{
    cin >> n;
    vector<pair<int, int>> act(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> act[i].first >> act[i].second;
    }
    sort(act.begin(), act.end(), [](const pair<int, int> &a, const pair<int, int> &b)
         { return a.second < b.second; });
    int ans = 0;
    int last = 0;
    for (int i = 0; i < n; ++i)
    {
        if (act[i].first >= last)
        {
            ++ans;
            last = act[i].second;
        }
    }
    cout << ans << endl;
    return 0;
}