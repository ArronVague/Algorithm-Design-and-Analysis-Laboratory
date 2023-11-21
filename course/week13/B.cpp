// https://vjudge.net/contest/595692#problem/B 统计难题

#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
    map<string, int> mp;
    string s;
    while (getline(cin, s))
    {
        if (s.empty())
        {
            break;
        }
        while (s.size() > 0)
        {
            mp[s]++;
            s.pop_back();
        }
    }
    while (getline(cin, s))
    {
        cout << mp[s] << endl;
    }
    return 0;
}