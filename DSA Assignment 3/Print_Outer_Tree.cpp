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
void levelOrder(Node *root)
{
    if(root==NULL) return;
    queue<Node *> q;
    if (root)
    {
        q.push(root);
    }
    while (!q.empty())
    {
        Node* p=q.front();
        q.pop();
        cout<<p->val<<" ";

        if(p->left)
        {
            q.push(p->left);
        }
        if(p->right)
        {
            q.push(p->right);
        }
    }
}
Node *inputTree()
{
    int val;
    cin >> val;
    Node *root;
    if (val == -1)
    {
        root == NULL;
    }
    else
    {
        root = new Node(val);
    }
    queue<Node *> q;
    if (root)
    {
        q.push(root);
    }
    while (!q.empty())
    {
        Node *p = q.front();
        q.pop();

        int l, r;
        cin >> l >> r;

        Node *myLeft;
        Node *myRight;
        if (l == -1)
        {
            myLeft = NULL;
        }
        else
        {
            myLeft = new Node(l);
        }
        if (r == -1)
        {
            myRight = NULL;
        }
        else
        {
            myRight = new Node(r);
        }

        p->left = myLeft;
        p->right = myRight;

        if (p->left)
        {
            q.push(p->left);
        }
        if (p->right)
        {
            q.push(p->right);
        }
    }
    return root;
}
void leftOuter(Node* root)
{
  if(root==NULL) return;
 if(root->left)
 {
     leftOuter(root->left);
 }
 else
 {
     leftOuter(root->right);
 }
  cout<<root->val<<" ";
}
void rightOuter(Node* root)
{
    if(root==NULL) return;
    cout<<root->val<<" ";
    if(root->right)
    {
        rightOuter(root->right);
    }
    else{
        rightOuter(root->left);
    }
}
int main()
{
    Node *root = inputTree();
    // levelOrder(root);
    leftOuter(root->left);
    cout<<root->val<<" ";
    rightOuter(root->right);
    return 0;
}