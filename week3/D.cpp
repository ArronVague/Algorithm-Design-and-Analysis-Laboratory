#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N, M;
    while (cin >> N >> M && N && M)
    {
        vector<int> a(N);
        for (int i = 0; i < N; ++i)
        {
            a[i] = i + 1;
        }
        int cnt = 0;
        do
        {
            if (++cnt == M)
            {
                int i;
                for (i = 0; i < N - 1; ++i)
                {
                    cout << a[i] << " ";
                }
                cout << a[i] << endl;
                break;
            }
        } while (next_permutation(a.begin(), a.end()));
    }
    return 0;
}