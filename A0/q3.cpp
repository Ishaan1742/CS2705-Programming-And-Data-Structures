#include<bits/stdc++.h>
using namespace std;

int number_of_subarrays_with_product_divisible_by_five(vector<int> a)
{
    int n = a.size();
    int count = 0; // count of subarrays with product divisible by 5
    int curr_add = 0; // number of subarrays to be added if current element is not a multiple of 5
    for(int i=0; i<n; i++)
    {
        if(a[i]%5==0) 
        {
            count += i+1; 
            curr_add = i+1; 
        }
        else
        {
            count += curr_add; 
        }
    }
    return count;
}

int main()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<number_of_subarrays_with_product_divisible_by_five(a)<<endl;
}