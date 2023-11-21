#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<string> str;
    string s;
    while (cin >> s && s != "")
    {
        // cout << s;
        char start = s[0];
        if (isdigit(start))
        {
            reverse(s.begin(), s.end());
        }
        else if (isupper(start))
        {
            transform(s.begin(), s.end(), s.begin(), ::tolower);
        }
        else
        {
            transform(s.begin(), s.end(), s.begin(), ::toupper);
        }
        str.push_back(s);
    }
    for (int i = str.size() - 1; i >= 0; i--)
    {
        cout << str[i] << " ";
    }
    return 0;
}