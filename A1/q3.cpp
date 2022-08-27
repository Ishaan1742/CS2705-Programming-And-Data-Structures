#include<bits/stdc++.h>
using namespace std;

void median_of_two_sorted_arrays(vector<int> a, vector<int> b, int m, int n)
{
    int i = 0, j = 0;
    bool even = (m + n) % 2 == 0;
    int k = (m + n) / 2;
    int count = 0;
    //we are using the two pointer technique to find the median of two sorted arrays
    //we start the two pointers at 0 each and move them one step at a time, based on the value of the current elements
    //we have also taken care of the case where one of the pointers has reached the end of the array, in which case it will not be incremented further
    //we do this until we reach the required elements for calculation of median
    if(even == false) //we only need the middle element
    {
        while(count < k) //we change the two pointers until we reach the required element.
        {
            if(i==m)
            {
                j++;
            }
            else if(j==n)
            {
                i++;
            }
            else if(a[i]<b[j])
            {
                i++;
            }
            else
            {
                j++;
            }
            count++;
        }
        //we have reached the required element, we can now print the median
        if(i==m)
        {
            cout<<b[j];
        }
        else if(j==n)
        {
            cout<<a[i];
        }
        else if(a[i]<b[j])
        {
            cout<<a[i];
        }
        else
        {
            cout<<b[j];
        }
    }
    else //we need the two middle elements this time
    {
        while(count < k-1)
        {
            if(i==m)
            {
                j++;
            }
            else if(j==n)
            {
                i++;
            }
            else if(a[i]<b[j])
            {
                i++;
            }
            else
            {
                j++;
            }
            count++;
        }
        //now repeating the same two pointer process, just twice to find the two middle elements.
        int x, y;
        if(i==m)
        {
            x = b[j];
            j++;
        }
        else if(j==n)
        {
            x = a[i];
            i++;
        }
        else if(a[i]<b[j])
        {
            x = a[i];
            i++;
        }
        else
        {
            x = b[j];
            j++;
        }
        if(i==m)
        {
            y = b[j];
        }
        else if(j==n)
        {
            y = a[i];
        }
        else if(a[i]<b[j])
        {
            y = a[i];
        }
        else
        {
            y = b[j];
        }
        //print the median upto 2 decimal places
        cout<<fixed<<setprecision(2)<<(x+y)/2.0;
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int m, n;
    cin >> m >> n;
    vector<int> a(m);
    vector<int> b(n);
    for(int i = 0; i < m; i++)
        cin >> a[i];
    for(int i = 0; i < n; i++)
        cin >> b[i];
    median_of_two_sorted_arrays(a, b, m, n);
}
