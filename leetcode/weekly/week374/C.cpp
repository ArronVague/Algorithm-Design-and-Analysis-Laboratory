#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countCompleteSubstrings(string word, int k)
    {
        map<char, int> cnt;
        int n = word.size();

        int l = 0;

        vector<string> su;
        for (int r = 0; r < n; ++r)
        {
            if (r > 0)
            {
                int gap = abs(word[r] - word[r - 1]);
                if (gap > 2 && gap < 24)
                {
                    cnt.clear();
                    l = r;
                }
            }
            cnt[word[r]]++;
            while (cnt[word[r]] > k)
            {
                cnt[word[l]]--;
                l++;
            }

            if (cnt[word[r]] == k)
            {
                bool check = true;
                for (const auto &pair : cnt)
                {
                    if (pair.second != k)
                    {
                        check = false;
                        break;
                    }
                }
                if (check)
                {
                    su.push_back(word.substr(l, r - l + 1));
                    l = r + 1;
                    cnt.clear();
                }
            }
        }

        for (auto s : su)
        {
            cout << s << endl;
        }

        int start = 0;
        int end = 1;
        int m = su.size();
        int ans = 0;
        while (end < m)
        {
            int gap = abs(su[end - 1][su[end - 1].size() - 1] - su[end][0]);
            if (gap > 2 && gap < 24)
            {
                cout << start << " " << gap << endl;
                int len = end - start;
                ans += len * (len + 1) / 2;
                start = end;
                end = start + 1;
            }
            end++;
        }
        return ans;
    }
};