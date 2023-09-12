#include <iostream>
#include <unordered_map>
#include <queue>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;

int N, M;

int main()
{
    int cnt = 1;
    while (cin >> N)
    {
        vector<string> a(N);
        unordered_map<string, int> m;
        for (int i = 0; i < N; ++i)
        {
            cin >> a[i];
            m[a[i]] = i;
        }
        cin >> M;
        vector<int> indeg(N);
        vector<vector<int>> g(N);
        getchar();
        while (M--)
        {
            string s;
            getline(cin, s);
            int pos = s.find(' ');
            string pre = s.substr(0, pos);
            string suf = s.substr(pos + 1);
            indeg[m[suf]]++;
            g[m[pre]].push_back(m[suf]);
        }
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < N; ++i)
        {
            if (indeg[i] == 0)
            {
                pq.push(i);
            }
        }
        cout << "Case #" << cnt << ": Dilbert should drink beverages in this order:";
        while (!pq.empty())
        {
            int cur = pq.top();
            pq.pop();
            cout << " " << a[cur];
            for (auto &nxt : g[cur])
            {
                if (--indeg[nxt] == 0)
                {
                    pq.push(nxt);
                }
            }
        }
        cout << "." << endl
             << endl;
        cnt++;
    }
    return 0;
}