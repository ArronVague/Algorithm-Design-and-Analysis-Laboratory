#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> in(N), out(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> in[i];
    }
    for (int i = 0; i < N; ++i)
    {
        cin >> out[i];
    }
    bool s = true;
    bool q = true;
    for (int i = 0; i < N; ++i)
    {
        if (in[i] != out[i])
        {
            q = false;
        }
        if (in[i] != out[N - 1 - i])
        {
            s = false;
        }
    }
    if (q && s)
    {
        cout << "both";
    }
    else if (q)
    {
        cout << "queue";
    }
    else if (s)
    {
        cout << "stack";
    }
    else
    {
        cout << "neither";
    }
    return 0;
}