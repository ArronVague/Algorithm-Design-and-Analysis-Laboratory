#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;
#define ll long long

const int base = 65537;
const int MOD = 1e9 + 7;

ll getHash(string s)
{
    ll res = 0;
    for (int i = 0; i < s.size(); ++i)
    {
        res = (res * base + (s[i] - 'a')) % MOD;
    }
    return res;
}

vector<string> a;
unordered_map<ll, int> m;
int main()
{
    string s;
    while (getline(cin, s) && s != "@END@")
    {
        int pos = s.find(']');
        string pre = s.substr(0, pos + 1);
        string suf = s.substr(pos + 2);
        a.push_back(pre);
        a.push_back(suf);
        m[getHash(pre)] = a.size() - 1;
        m[getHash(suf)] = a.size() - 2;
    }
    int N;
    cin >> N;
    getchar();
    while (N--)
    {
        getline(cin, s);
        ll idx = getHash(s);
        if (m.count(idx))
        {
            string t = a[m[idx]];
            if (t[0] == '[')
            {
                cout << t.substr(1, t.size() - 2) << endl;
            }
            else
            {
                cout << t << endl;
            }
        }
        else
        {
            cout << "what?" << endl;
        }
    }
}