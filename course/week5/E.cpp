#include <bits/stdc++.h>
using namespace std;

string num;
int k;

int main()
{
    cin >> num;
    cin >> k;
    while (k--)
    {
        int i = 0;
        while (i < num.size() - 1 && num[i] <= num[i + 1])
        {
            i++;
        }
        num.erase(i, 1);
    }
    while (num.size() > 1 && num[0] == '0')
    {
        num.erase(0, 1);
    }
    cout << num << endl;
    return 0;
}