#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};
int max_level = 0;
void levelOrder(Node *root, int x)
{
    if (root == NULL)
        return;
    queue<pair<Node *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        pair<Node *, int> p = q.front();
        Node *node = p.first;
        int level = p.second;
        q.pop();

        // print

        if (level == x)
        {
            cout << node->val << " ";
        }

        //    push queue
        if (node->left)
            q.push({node->left, level + 1});
        if (node->right)
            q.push({node->right, level + 1});
    }
}

Node *inputTree()
{
    int val;
    cin >> val;
    Node *root;

    if (val == -1)
        root = NULL;
    else
    {
        root = new Node(val);
    }
    queue<pair<Node *, int>> q;
    if (root)
        q.push({root, 0});
    while (!q.empty())
    {
        pair<Node *, int> p = q.front();
        Node *node = p.first;
        int level = p.second;
        q.pop();
        if (p.second > max_level)
        {
            max_level = p.second;
        }

        int l, r;
        cin >> l >> r;
        Node *myLeft;
        Node *myRight;
        if (l == -1)
            myLeft = NULL;
        else
        {
            myLeft = new Node(l);
        }
        if (r == -1)
            myRight = NULL;
        else
        {
            myRight = new Node(r);
        }

        node->left = myLeft;
        node->right = myRight;

        if (node->left)
        {
            q.push({node->left, level + 1});
        }
        if (node->right)
        {
            q.push({node->right, level + 1});
        }
        // cout<<"Added Successfully"<<endl;-1
    }
    return root;
}

int main()
{
    Node *root = inputTree();
    // cout << max_level;
    int x;
    cin >> x;
    if(x>max_level)
    {
        cout<<"Invalid"<<endl;
    }
    else{
        levelOrder(root,x);
    }
}