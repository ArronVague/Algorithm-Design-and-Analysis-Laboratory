#include <iostream>
#include <vector>
using namespace std;

int N;

bool check(int a, int b)
{
    vector<int> vis(10, 0);
    while (a)
    {
        vis[a % 10] += 1;
        a /= 10;
    }
    while (b)
    {
        vis[b % 10] += 1;
        b /= 10;
    }
    for (int i = 1; i < 10; ++i)
    {
        if (vis[i] != 1)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int ncase = 0;
    while (cin >> N && N)
    {
        if (ncase++)
        {
            cout << endl;
        }
        int base = 1234;
        bool flag = false;
        while (base * N <= 98765)
        {
            if (check(base, base * N))
            {
                flag = true;
                printf("%05d / %05d = %d\n", base * N, base, N);
            }
            base += 1;
        }
        if (!flag)
        {
            printf("There are no solutions for %d.\n", N);
        }
    }
}