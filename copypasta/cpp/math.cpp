#include <bits/stdc++.h>
using namespace std;

void sieve()
{
    const int mx = 1e6;
    vector<int> primes;
    vector<int> pid(mx + 1, 0);
    pid[0] = -1;
    pid[1] = -1;
    for (int i = 2; i <= mx; i++)
    {
        if (pid[i] == 0)
        {
            primes.push_back(i);
            pid[i] = primes.size();
            for (int j = i * i; j <= mx; j += i)
                pid[j] = -1;
        }
    }

    // 或者，知识单纯想标记一下
    vector<bool> np(mx + 1, false);
    np[0] = true;
    np[1] = true;
    for (int i = 2; i <= mx; i++)
    {
        if (!np[i])
        {
            for (int j = i * i; j <= mx; j += i)
                np[j] = true;
        }
    }

    // EXTRA: pi(n), the number of primes <= n https://oeis.org/A000720
    vector<int> pi(mx + 1, 0);
    for (int i = 2; i <= mx; i++)
    {
        pi[i] = pi[i - 1];
        if (pid[i] > 0)
        {
            pi[i]++;
        }
    }
}