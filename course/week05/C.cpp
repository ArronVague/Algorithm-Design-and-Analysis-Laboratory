#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n;
vector<pair<int, int>> cow;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int res[50001];
vector<int> idx;

bool cmp(int a, int b)
{
    return cow[a].first < cow[b].first;
}

bool cmp2(pair<int, int> a, pair<int, int> b)
{
    return a.first < b.first;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;
        cow.push_back(make_pair(a, b));
        idx.push_back(i);
    }
    sort(idx.begin(), idx.end(), [](const int &a, const int &b)
         { return cow[a].first < cow[b].first; });
    sort(cow.begin(), cow.end(), cmp2);
    // cout << cow[0].first << " " << cow[0].second << endl;
    for (int i = 0; i < n; ++i)
    {
        pair<int, int> c = cow[i];
        if (pq.empty() || pq.top().first >= c.first)
        {
            pair<int, int> t;
            t.first = c.second;
            t.second = pq.size();
            res[idx[i]] = pq.size();
            pq.push(t);
            // cout << pq.top().first << " " << pq.top().second << endl;
        }
        else
        {
            // cout << pq.top().first << " " << pq.top().second << endl;
            pair<int, int> t = pq.top();
            pq.pop();
            t.first = c.second;
            res[idx[i]] = t.second;
            pq.push(t);
        }
    }
    cout << pq.size() << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << res[i] + 1 << endl;
    }
    return 0;
}