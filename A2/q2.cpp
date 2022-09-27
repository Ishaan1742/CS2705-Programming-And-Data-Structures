#include<bits/stdc++.h>
using namespace std;

vector<int> next_greater_element(vector<int> a)
{
    const int n = a.size();
    vector<int> nge(n);
    stack<int> s;
    s.push(0);
    for(int i=1; i<n; i++)
    {
        while(!s.empty() && a[s.top()] < a[i])
        {
            nge[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
    while(!s.empty())
    {
        nge[s.top()] = -1;
        s.pop();
    }
    return nge;
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++)
        cin >> a[i];
    vector<int> nge = next_greater_element(a);
    for(int i=0; i<n; i++)
        nge[i] != -1 ? cout << nge[i] - i << " " : cout << "Inf" << " ";
    cout << endl;
    return 0;
}
