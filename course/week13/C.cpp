#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e6 + 10;

int nxt[maxN];
string s1, s2;

int main()
{
    cin >> s1;
    cin >> s2;
    nxt[0] = nxt[1] = 0;
    for (int i = 1; i < s2.size(); i++)
    {
        int j = nxt[i];
        while (j && s2[i] != s2[j])
        {
            j = nxt[j];
        }
        nxt[i + 1] = s2[i] == s2[j] ? j + 1 : 0;
    }
    int j = 0;
    for (int i = 0; i < s1.size(); i++)
    {
        while (j && s1[i] != s2[j])
        {
            j = nxt[j];
        }
        if (s1[i] == s2[j])
        {
            j++;
        }
        if (j == s2.size())
        {
            cout << i - s2.size() + 2 << endl;
            j = nxt[j];
        }
    }
    for (int i = 1; i <= s2.size(); i++)
    {
        cout << nxt[i] << " ";
    }
    return 0;
}