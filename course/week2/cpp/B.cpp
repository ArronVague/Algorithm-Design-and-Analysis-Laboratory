#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct person
{
    int level;
    int id;
};

bool operator<(const person &a, const person &b)
{
    if (a.level == b.level)
    {
        return a.id > b.id;
    }
    return a.level < b.level;
}

int N;

int main()
{
    while (cin >> N)
    {
        priority_queue<person> pq[4];
        int cnt = 1;
        for (int i = 1; i <= N; ++i)
        {
            string io;
            int doc;
            int level;
            cin >> io;
            if (io == "IN")
            {
                cin >> doc >> level;
                pq[doc].push({level, cnt});
                cnt++;
            }
            else
            {
                cin >> doc;
                if (!pq[doc].empty())
                {
                    cout << pq[doc].top().id << endl;
                    pq[doc].pop();
                }
                else
                {
                    cout << "EMPTY" << endl;
                }
            }
        }
    }
}