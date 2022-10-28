#include<bits/stdc++.h>
using namespace std;

void number_of_secure_rooms(int n, int m, vector<vector<int>> graph)
{
    //reverse the graph
    vector<vector<int>> reverse_graph(n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<graph[i].size();j++)
        {
            reverse_graph[graph[i][j]].push_back(i);
        }
    }
    //topological sort of reverse graph
    vector<bool> topological_sort(n,false);
    vector<int> inDegree(n,0);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<reverse_graph[i].size();j++)
        {
            inDegree[reverse_graph[i][j]]++;
        }
    }   
    queue<int> q;
    for(int i=0;i<n;i++)
    {
        if(inDegree[i]==0)
        {
            q.push(i);
        }
    }
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        topological_sort[node]=true;
        for(int i=0;i<reverse_graph[node].size();i++)
        {
            inDegree[reverse_graph[node][i]]--;
            if(inDegree[reverse_graph[node][i]]==0)
            {
                q.push(reverse_graph[node][i]);
            }
        }
    }
    //print topological sort
    for(int i=0;i<n;i++)
    {
        if(topological_sort[i])
        {
            cout<<i<<" ";
        }
    }
}


int main()
{
    //declaring a directed graph
    int n, m;
    cin>>n>>m;
    vector<vector<int>> graph(n);
    for(int i=0; i<m; i++)
    {
        int u, v;
        cin>>u>>v;
        graph[u].push_back(v);
    }
    number_of_secure_rooms(n, m, graph);
}
