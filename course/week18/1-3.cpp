#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> f(31);
    f[0] = 1;
    f[1] = 1;
    for (int i = 2; i <= 30; ++i)
    {
        f[i] = f[i - 2] + f[i - 1];
    }

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        cout << f[n] << endl;
    }
    return 0;
}