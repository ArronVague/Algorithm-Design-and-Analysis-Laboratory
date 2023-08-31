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
    for (int i = arr.size() - 1; m > 0 && i >= 0; i--, m--)
    {
        cout << arr[i] << " ";
    }
    return 0;
}