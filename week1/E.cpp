#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int N, C;

struct Student
{
    string id;
    string name;
    int score;
};

int main()
{
    int cnt = 1;
    while (cin >> N >> C && N)
    {
        vector<Student> students(N);
        for (int i = 0; i < N; ++i)
        {
            cin >> students[i].id >> students[i].name >> students[i].score;
        }
        if (C == 1)
        {
            sort(students.begin(), students.end(), [](const Student &a, const Student &b)
                 { return a.id < b.id; });
        }
        else if (C == 2)
        {
            sort(students.begin(), students.end(), [](const Student &a, const Student &b)
                 {
                if (a.name != b.name) {
                    return a.name < b.name;
                }
                return a.id < b.id; });
        }
        else
        {
            sort(students.begin(), students.end(), [](const Student &a, const Student &b)
                 {
                if (a.score != b.score) {
                    return a.score < b.score;
                }
                return a.id < b.id; });
        }
        cout << "Case " << cnt << ":" << endl;
        for (int i = 0; i < N; ++i)
        {
            cout << students[i].id << " " << students[i].name << " " << students[i].score << endl;
        }
        cnt++;
    }
    return 0;
}