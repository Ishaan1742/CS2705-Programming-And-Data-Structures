#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

Node* create_tree_from_level_order(vector<int> a)
{
    Node* root = new Node(a[0]);
    queue<Node*> q;
    q.push(root);
    int i = 1;
    while(!q.empty())
    {
        Node* temp = q.front();
        q.pop();
        if(i <= a.size())
        {
            if(a[i] != -1)
            {
                temp->left = new Node(a[i]);
                q.push(temp->left);
            }
            i++;
        }
        if(i <= a.size())
        {
            if(a[i] != -1)
            {
                temp->right = new Node(a[i]);
                q.push(temp->right);
            }
            i++;
        }
    }
    return root;
}

void print_level_order(Node* root)
{
    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        Node* temp = q.front();
        q.pop();
        cout << temp->data << " ";
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
    }
}

void print_inorder(Node* root)
{
    if(root == NULL)
        return;
    print_inorder(root->left);
    cout << root->data << " ";
    print_inorder(root->right);
}


int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    Node* root = create_tree_from_level_order(a);
    print_level_order(root);
    cout << endl;
    print_inorder(root);
    return 0;
}
