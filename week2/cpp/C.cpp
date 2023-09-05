#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

int N;
const int MOD = 1e9 + 7;
const int base = 31;
unordered_set<int> s;

int getHash(string s)
{
    int res = 0;
    for (int i = 0; i < s.size(); ++i)
    {
        res = (res * base + (s[i] - 'a')) % MOD;
    }
    return res;
}

int main()
{
    cin >> N;
    while (N--)
    {
        string str;
        cin >> str;
        s.insert(getHash(str));
    }
    cout << s.size();
}