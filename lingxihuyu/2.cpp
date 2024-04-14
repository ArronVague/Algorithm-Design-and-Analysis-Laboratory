#include <bits/stdc++.h>
using namespace std;

int main()
{
    int man, med;
    cin >> man >> med;
    vector<int> l_man(man), l_med(med);
    for (int i = 0; i < man; i++)
    {
        cin >> l_man[i];
    }
    for (int i = 0; i < med; i++)
    {
        cin >> l_med[i];
    }
    sort(l_man.begin(), l_man.end());
    sort(l_med.begin(), l_med.end());
    int p = 0;
    int m = 0;
    int ans = 0;
    while (p < med && m < man)
    {
        if (l_med[p] > l_man[m])
        {
            m++;
            ans++;
        }
        p++;
    }
    cout << ans;
}