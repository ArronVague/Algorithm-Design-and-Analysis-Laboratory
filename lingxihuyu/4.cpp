#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    getline(cin, s);
    stack<long long> num;
    stack<char> op;
    string n = "";
    for (auto c : s)
    {
        if (c >= '0' && c <= '9')
        {
            n.push_back(c);
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/')
        {
            long long right = stoll(n);
            n.clear();
            while (!op.empty() && (op.top() == '+' || op.top() == '-'))
            {
                long long t = num.top();
                num.pop();
                char o = op.top();
                op.pop();
                if (o == '+')
                {
                    right = t + right;
                }
                else
                {
                    right = t - right;
                }
            }
            num.push(right);
            op.push(c);
        }
    }
    long long right = stoll(n);
    while (op.size())
    {
        int t = num.top();
        num.pop();
        char o = op.top();
        op.pop();
        if (o == '+')
        {
            right = t + right;
        }
        else if (o == '-')
        {
            right = t - right;
        }
        else if (o == '*')
        {
            right = t * right;
        }
        else
        {
            right = t / right;
        }
    }
    printf("%lld\n", right);
}