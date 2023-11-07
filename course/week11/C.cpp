#include <iostream>
using namespace std;

const int maxN = 1e6 + 1;
int n;
int x, y;

struct node
{
    int l, r;
} tree[maxN];

void preOrder(int root)
{
    if (root == 0)
        return;
    cout << root << " ";
    if (tree[root].l != 0)
    {
        preOrder(tree[root].l);
    }
    if (tree[root].r != 0)
    {
        preOrder(tree[root].r);
    }
}

void inOrder(int root)
{
    if (root == 0)
        return;
    if (tree[root].l != 0)
    {
        inOrder(tree[root].l);
    }
    cout << root << " ";
    if (tree[root].r != 0)
    {
        inOrder(tree[root].r);
    }
}

void postOrder(int root)
{
    if (root == 0)
        return;
    if (tree[root].l != 0)
    {
        postOrder(tree[root].l);
    }
    if (tree[root].r != 0)
    {
        postOrder(tree[root].r);
    }
    cout << root << " ";
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> x >> y;
        tree[i].l = x;
        tree[i].r = y;
    }
    preOrder(1);
    cout << endl;
    inOrder(1);
    cout << endl;
    postOrder(1);
    cout << endl;
}