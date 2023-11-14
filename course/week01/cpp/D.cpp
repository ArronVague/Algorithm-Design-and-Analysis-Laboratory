#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, Q;

int main()
{
    int cnt = 1;
    while (cin >> N >> Q)
    {
        if (!N && !Q)
        {
            break;
        }
        vector<int> arr(N);
        for (int i = 0; i < N; i++)
        {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());
        cout << "CASE# " << cnt << ":" << endl;
        for (int i = 0; i < Q; i++)
        {
            int q;
            cin >> q;
            int idx = lower_bound(arr.begin(), arr.end(), q) - arr.begin();
            if (idx < N && arr[idx] == q)
            {
                cout << q << " found at " << idx + 1 << endl;
            }
            else
            {
                cout << q << " not found" << endl;
            }
        }
        cnt++;
    }
    return 0;
}