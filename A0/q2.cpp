#include<bits/stdc++.h>
using namespace std;

int find_missing_naive(vector<int> a, int n)
{
    vector<bool> b(n+2,false); // b[i] is true if i is present in a
    for(int i=0;i<n;i++)
    {
        b[a[i]]=true;
    }
    for(int i=1;i<=n+1;i++)
    {
        if(!b[i])
            return i;
    }
    return -1;
}

int find_missing_efficient(vector<int> a, int n)
{
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=a[i];
    }
    return ((n+1)*(n+2))/2-sum; // formula for sum of 1 to n+1
}

int find_missing_efficient_xor(vector<int> a, int n)
{
    int x=0;
    for(int i=0;i<n;i++)
    {
        x^=a[i]; // xor of all elements
    }
    for(int i=1;i<=n+1;i++)
    {
        x^=i; // xor of all elements and 1 to n
    }
    return x; // return the missing element
}

int main()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<find_missing_efficient_xor(a,n)<<endl;
}