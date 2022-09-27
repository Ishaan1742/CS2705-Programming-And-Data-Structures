#include<bits/stdc++.h>
using namespace std;

#define INF 1000000

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
            else
            {
                temp->left = new Node(INF);
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
            else
            {
                temp->right = new Node(INF);
                q.push(temp->right);
            }
            i++;
        }
    }
    return root;
}

int number_of_paths_with_sum(Node* root, int sum)
{
    if(root == NULL)
        return 0;
    int count = 0;
    if(root->data == sum && root->left == NULL && root->right == NULL)
        count++;
    count += number_of_paths_with_sum(root->left, sum - root->data);
    count += number_of_paths_with_sum(root->right, sum - root->data);
    return count;
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
    int sum;
    cin >> sum;
    cout << number_of_paths_with_sum(root, sum) << endl;
    return 0;
}
