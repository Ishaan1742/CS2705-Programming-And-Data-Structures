#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int cnt = 0;
    for(int i=1; i<=1000; i++)
    {
        if(i%3!=0 and i%5!=0 and i%7!=0)
            cnt++;
    }
    cout<<cnt<<endl;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t=1;
    //cin>>t;
    while(t--)
    solve();
}
