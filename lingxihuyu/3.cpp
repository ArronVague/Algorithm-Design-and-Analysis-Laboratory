#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        map<char, int> m;
        string s1, s2;
        cin >> s1;
        cin >> s2;
        for (auto c : s1)
        {
            m[c]++;
        }
        int left = 0;
        map<char, int> m2;
        int i = 0;
        for (; i < s1.size(); i++)
        {
            m2[s2[i]]++;
        }
        bool flag = m == m2;
        while (i < s2.size())
        {
            m2[s2[i]]++;
            m2[s2[left]]--;
            if (m2[s2[left]] == 0)
            {
                m2.erase(s2[left]);
            }
            i++;
            left++;
            if (m == m2)
            {
                flag = true;
                break;
            }
        }
        if (flag)
        {
            cout << "true" << endl;
        }
        else
        {
            cout << "false" << endl;
        }
    }
}