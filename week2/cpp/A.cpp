#include <iostream>
#include <stack>
#include <vector>
#include <cstring>
using namespace std;

int n;

int main()
{
    cin >> n;
    int a[n + 1] = {0};

    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    stack<int> s;
    int ans[n + 1];
    memset(ans, 0, sizeof(ans));
    for (int i = 1; i <= n; ++i)
    {
        while (!s.empty() && a[s.top()] < a[i])
        {
            ans[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
    for (int i = 1; i <= n; ++i)
    {
        cout << ans[i] << " ";
    }
}