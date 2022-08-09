#include<bits/stdc++.h>
using namespace std;

int computeFib(int n) // recursive approach to calculate fibonacci number
{
    if(n==0)
        return 0;
    if(n==1)
        return 1;
    return computeFib(n-1)+computeFib(n-2);
}

int smartFib(int n) // iterative approach to calculate fibonacci number
{
    if(n==0)
        return 0;
    int a=0,b=1,c=1;
    for(int i=0;i<n-1;i++) // loop to calculate fibonacci number
    {
        c=a+b;
        a=b;
        b=c;
    }
    return c;
}

int main()
{
    int n;
    cin>>n;
    int func;
    cin>>func;
    clock_t start,end; // clock_t is a data type for storing time
    start=clock(); // start the clock
    if(func==0)
        cout<<computeFib(n)<<" ";
    else if(func==1)
        cout<<smartFib(n)<<" ";
    end=clock(); // end the clock
    cout<<(double)(end-start)/CLOCKS_PER_SEC<<endl; // print the time taken
    return 0;
}