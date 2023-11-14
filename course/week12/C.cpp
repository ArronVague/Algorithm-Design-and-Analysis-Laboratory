#include <iostream>
#include <map>
using namespace std;

map<int, int> mp;
int n;
int k, g;

int main()
{
    while (cin >> n && n)
    {
        mp.clear();
        mp[1e9] = 1;
        while (n--)
        {
            cin >> k >> g;
            mp[g] = k;
            auto it = mp.find(g);
            int ans;
            if (it == mp.begin())
            {
                ans = (++it)->second;
            }
            else
            {
                auto before = it;
                --before;
                it++;
                ans = g - before->first <= it->first - g ? before->second : it->second;
            }
            cout << k << " " << ans << '\n';
        }
    }
}