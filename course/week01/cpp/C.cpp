#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> arr;
    int cnt = 0;
    while (cnt < n)
    {
        int x;
        cin >> x;
        arr.push_back(x);
        cnt++;
    }
    sort(arr.begin(), arr.end());
    int idx = arr.size() - 1;
    while (m > 0 && idx >= 0)
    {
        cout << arr[idx] << " ";
        m--;
        idx--;
    }
    return 0;
}