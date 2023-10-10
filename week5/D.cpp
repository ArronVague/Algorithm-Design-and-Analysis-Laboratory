#include <bits/stdc++.h>
using namespace std;

int N;
int card[100];

int main()
{
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> card[i];
    }
    int target = accumulate(card, card + N, 0) / N;
    int ans = 0;
    for (int i = 0; i < N - 1; ++i)
    {
        if (card[i] != target)
        {
            ans++;
            card[i + 1] += card[i] - target;
        }
    }
    cout << ans << endl;
}