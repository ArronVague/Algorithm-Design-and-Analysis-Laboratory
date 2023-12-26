#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> ans;
string ipp;

bool check(string str)
{
    int pos = 0;
    // cout << str << endl;
    for (int i = 0; i < str.size(); ++i)
    {

        int len = str[i] - '0';
        string sub = ipp.substr(pos, len);
        if (sub[0] == '0' && len > 1)
        {
            return false;
        }
        // cout << pos << " " << len << endl;
        pos += len;
        // cout << stoi(sub) << endl;
        // cout << stoi(sub) << endl;
        if (stoi(sub) > 255)
        {

            return false;
        }
    }
    return true;
}

string add(string str)
{
    string tmp;
    int pos = 0;
    for (int i = 0; i < str.size() - 1; ++i)
    {
        int len = str[i] - '0';
        string sub = ipp.substr(pos, len);
        pos += len;
        tmp += sub;
        tmp += ".";
    }
    tmp += ipp.substr(pos, str[3] - '0');
    // cout << tmp << endl;
    return tmp;
}

void dfs(string len, int total)
{

    if (len.size() == 4)
    {
        // cout << len << endl;
        if (check(len))
        {
            ans.push_back(add(len));
        }
        return;
    }
    if (total >= ipp.size())
    {
        return;
    }

    if (len.size() == 3)
    {
        int t_len = ipp.size() - total;
        dfs(len + to_string(t_len), total + t_len);
    }
    else
    {
        for (int i = 1; i <= 3; ++i)
        {
            int t_len = i;
            dfs(len + to_string(t_len), total + t_len);
        }
    }
}

int main()
{
    cin >> ipp;
    // ipp = ipp.substr(1, ipp.size() - 2);
    string len = "";
    dfs(len, 0);
    // cout << ans.size() << endl;
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); ++i)
    {
        cout << ans[i] << endl;
    }
    return 0;
}