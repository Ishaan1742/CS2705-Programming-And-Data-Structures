#include<bits/stdc++.h>
using namespace std;

int number_of_k_strangers(int n, int m, int k, vector<vector<int>> graph)
{
    vector<vector<bool>> distance_more_than_k(n, vector<bool>(n, false));
    //run bfs for each node and find the distance of each node from it
    //if distance is more than k then mark it as true
    for(int i = 0; i < n; i++)
    {
        vector<bool> visited(n, false);
        queue<pair<int, int>> q;
        q.push({i, 0});
        visited[i] = true;
        while(!q.empty())
        {
            pair<int, int> p = q.front();
            q.pop();
            if(p.second > k)
            {
                distance_more_than_k[i][p.first] = true;
            }
            for(int j = 0; j < graph[p.first].size(); j++)
            {
                if(!visited[graph[p.first][j]])
                {
                    q.push({graph[p.first][j], p.second + 1});
                    visited[graph[p.first][j]] = true;
                }
            }
        }
    }
    int count = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(distance_more_than_k[i][j] && distance_more_than_k[j][i])
            {
                count++;
            }
        }
    }
    return count;
}



int main()
{
    //declaring an undirected graph indicating the social network
    int n, k, m;
    cin>>n>>k>>m;
    vector<vector<int>> graph(n);
    for(int i=0;i<m;i++)
    {
        int u, v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    cout<<number_of_k_strangers(n, m, k, graph)<<endl;
}
