#include<bits/stdc++.h>
using namespace std;

void unoccupied_slots_in_windows_naive(vector<vector<bool>> students, vector<vector<int>> windows)
{
    int w = windows.size();
    for(int i=0; i<w; i++)
    {
        int x1 = windows[i][0];
        int y1 = windows[i][1];
        int x2 = windows[i][2];
        int y2 = windows[i][3];
        int unoccupied = 0;
        for(int i=x1; i<=x2; i++)
        {
            for(int j=y1; j<=y2; j++)
            {
                if(students[i][j] == false) // if the seat is unoccupied
                    unoccupied++;
            }
        }
        cout<<unoccupied<<"\n";
    }
}

void unoccupied_slots_in_windows_dp(vector<vector<bool>> students, vector<vector<int>> windows)
{
    //dynamic programming approach, we will precompute the number of unoccupied slots till each point
    int w = windows.size();
    int m = students.size();
    int n = students[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(students[i][j] == false)
            {
                if(i==0 && j==0)
                dp[i][j] = 1; // if the first seat is unoccupied
                else if(i==0)
                dp[i][j] = dp[i][j-1] + 1; // if we are in the first row, we can only come from the left
                else if(j==0)
                dp[i][j] = dp[i-1][j] + 1; // if we are in the first column, we can only come from the top
                else
                dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + 1; // we are adding 1 because the current point is unoccupied
            }
            else
            {
                if(i==0 && j==0)
                dp[i][j] = 0;
                else if(i==0)
                dp[i][j] = dp[i][j-1];
                else if(j==0)
                dp[i][j] = dp[i-1][j];
                else
                dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
            }
        }
    }
    for(int i=0; i<w; i++)
    {
        int x1 = windows[i][0];
        int y1 = windows[i][1];
        int x2 = windows[i][2];
        int y2 = windows[i][3];
        int unoccupied = 0;
        if(x1==0 && y1==0)
        unoccupied = dp[x2][y2]; //if both x1 and y1 are 0, then we need not subtract anything
        else if(x1==0)
        unoccupied = dp[x2][y2] - dp[x2][y1-1]; //if x1 is 0, then we need to subtract the unoccupied slots till y1-1
        else if(y1==0)
        unoccupied = dp[x2][y2] - dp[x1-1][y2]; //if y1 is 0, then we need to subtract the unoccupied slots till x1-1
        else
        unoccupied = dp[x2][y2] - dp[x1-1][y2] - dp[x2][y1-1] + dp[x1-1][y1-1]; //if both x1 and y1 are non-zero, then we need to subtract the unoccupied slots till x1-1 and y1-1
        cout<<unoccupied<<"\n";
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int m, n, s, w;
    cin>>m>>n>>s>>w;
    vector<vector<bool>> students(m, vector<bool>(n, false));
    vector<vector<int>> windows(w, vector<int> (4));
    //take input of students
    for(int i=0; i<s; i++)
    {
        //input is of the form "x,y" representing coordinates of student
        string input;
        cin>>input;
        int x = input[0] - '0';
        int y = input[2] - '0';
        students[x][y] = true; //mark the student's seat as occupied
    }
    //take input of windows
    for(int i=0; i<w; i++)
    {
        //input is of the form "x1,y1,x2,y2" representing left top and right bottom of window
        string input;
        cin>>input;
        windows[i][0] = input[0] - '0';
        windows[i][1] = input[2] - '0';
        windows[i][2] = input[4] - '0';
        windows[i][3] = input[6] - '0';
    }
    unoccupied_slots_in_windows_dp(students, windows);
}
