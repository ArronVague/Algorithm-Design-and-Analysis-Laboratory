#include <iostream>
#include <string>
#include <sstream>
#include <set>
using namespace std;

set<string> st;
int main()
{
    string str, word;
    while (cin >> str)
    {
        for (int i = 0; i < str.size(); ++i)
        {
            if (isalpha(str[i]))
            {
                str[i] = tolower(str[i]);
            }
            else
            {
                str[i] = ' ';
            }
        }
        stringstream ss(str);
        while (ss >> word)
        {
            st.insert(word);
        }
    }
    for (auto it = st.begin(); it != st.end(); ++it)
    {
        cout << *it << endl;
    }
    return 0;
}