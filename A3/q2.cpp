#include<bits/stdc++.h>
using namespace std;

int largest_strongly_connected_component(vector<vector<int>> &adj, vector<vector<int>> &rev_adj) {
  int n = adj.size();
  vector<bool> visited(n, false);
  vector<int> order;
  function<void(int)> dfs1 = [&](int u) {
    visited[u] = true;
    for (int v : adj[u]) {
      if (!visited[v]) {
        dfs1(v);
      }
    }
    order.push_back(u);
  };
  for (int i = 0; i < n; i++) {
    if (!visited[i]) {
      dfs1(i);
    }
  }
  reverse(order.begin(), order.end());
  fill(visited.begin(), visited.end(), false);
  int ans = 0;
  function<void(int)> dfs2 = [&](int u) {
    visited[u] = true;
    ans++;
    for (int v : rev_adj[u]) {
      if (!visited[v]) {
        dfs2(v);
      }
    }
  };
  //find size of largest strongly connected component
  int max_size = 0;
  for (int i = 0; i < n; i++) {
    if (!visited[order[i]]) {
      ans = 0;
      dfs2(order[i]);
    }
    max_size = max(max_size, ans);
  }
  return max_size;
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
    //declaring a reverse graph
    vector<vector<int>> rev_graph(n);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<graph[i].size(); j++)
        {
            rev_graph[graph[i][j]].push_back(i);
        }
    }
    cout<<largest_strongly_connected_component(graph, rev_graph);
    return 0;
}
