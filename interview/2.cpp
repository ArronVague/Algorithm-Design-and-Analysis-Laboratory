#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    node *left;
    node *right;
    int val;
};

int main()
{
    node *root;
    queue<node *> q;
    q.push(root);
    vector<int> ans;
    while (q.size())
    {
        int s = q.size();
        while (s--)
        {
            node *t = q.front();
            q.pop();
            ans.push_back(t->val);
            if (t->left)
            {
                q.push(t->left);
            }
            if (t->right)
            {
                q.push(t->right);
            }
        }
    }
}