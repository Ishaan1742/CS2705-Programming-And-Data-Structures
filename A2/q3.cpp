#include<bits/stdc++.h>
using namespace std;

#define INF 1000000

struct Node
{
    int data;
    Node* left;
    Node* right;
    Node* parent;

    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
        parent = NULL;
    }
};

void level_order(Node* root)
{
    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        Node* temp = q.front();
        q.pop();
        cout<<temp->data<<" ";
        if(temp->left != NULL)
            q.push(temp->left);
        if(temp->right != NULL)
            q.push(temp->right);
    }
}

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
                temp->left->parent = temp;
                q.push(temp->left);
            }
            else
            {
                temp->left = new Node(INF);
                temp->left->parent = temp;
                q.push(temp->left);
            }
            i++;
        }
        if(i <= a.size())
        {
            if(a[i] != -1)
            {
                temp->right = new Node(a[i]);
                temp->right->parent = temp;
                q.push(temp->right);
            }
            else
            {
                temp->right = new Node(INF);
                temp->right->parent = temp;
                q.push(temp->right);
            }
            i++;
        }
    }
    //delete all nodes with INF
    queue<Node*> q2;
    q2.push(root);
    while(!q2.empty())
    {
        Node* temp = q2.front();
        q2.pop();
        if(temp->left != NULL)
        {
            if(temp->left->data == INF)
            {
                temp->left = NULL;
            }
            else
            {
                q2.push(temp->left);
            }
        }
        if(temp->right != NULL)
        {
            if(temp->right->data == INF)
            {
                temp->right = NULL;
            }
            else
            {
                q2.push(temp->right);
            }
        }
    }
    return root;
}

int sum_with_given_root(Node* root)
{
    if(root == NULL)
    {
        return 0;
    }
    return root->data + sum_with_given_root(root->left) + sum_with_given_root(root->right);
}

Node* modify_tree(Node* root)
{
    //need to modify in such a way that only original 
    //tree values are used for every succesive computation 
    //and not the current changed values
    map<Node*, int> m;
    //store the sum of all nodes in the subtree rooted at each node
    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        Node* temp = q.front();
        q.pop();
        m[temp] = sum_with_given_root(temp);
        if(temp->left != NULL)
            q.push(temp->left);
        if(temp->right != NULL)
            q.push(temp->right);
    }
    //now modify the tree
    q.push(root);
    while(!q.empty())
    {
        Node* temp = q.front();
        q.pop();
        if(temp->parent != NULL && temp->parent->right == temp)
        {
            temp->data = m[temp->parent] - m[temp->left] - m[temp->right];
        }
        
        if(temp->left != NULL)
            q.push(temp->left);
        if(temp->right != NULL)
            q.push(temp->right);
    }
    return root;
}

int main()
{
    int n;
    cin >> n;
    vector<int> a;
    for(int i=0; i<n; i++)
    {
        int x;
        cin>>x;
        a.push_back(x);
        if(x == -1)
            i--;
    }
    Node* root = create_tree_from_level_order(a);
    root = modify_tree(root);
    level_order(root);
    return 0;
}

