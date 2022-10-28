#include<bits/stdc++.h>
using namespace std;

int number_of_k_strangers(int n, int m, int k, vector<vector<int>> graph)
{
    //find all pair shortest path
    vector<vector<int>> dist(n,vector<int>(n,INT_MAX));
    for(int i=0;i<n;i++)
    {
        dist[i][i]=0;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<graph[i].size();j++)
        {
            dist[i][graph[i][j]]=1;
        }
    }
    for(int k=0;k<n;k++) //Floyd Warshall Algorithm
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(dist[i][k]!=INT_MAX && dist[k][j]!=INT_MAX && dist[i][k]+dist[k][j]<dist[i][j])
                {
                    dist[i][j]=dist[i][k]+dist[k][j];
                }
            }
        }
    }
    //find number of k strangers
    int count=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(dist[i][j]>k)
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
