#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> arr;
    while (n--)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    sort(arr.begin(), arr.end());
    for (int i = arr.size() - 1; m > 0 && i >= 0; i--, m--)
    {
        cout << arr[i] << " ";
    }
    return 0;
}