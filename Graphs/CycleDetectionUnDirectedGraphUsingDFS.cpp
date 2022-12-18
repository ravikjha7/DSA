#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mod 1000000007

// Space Complexity : O(N + 2E) + O(N) + O(N)
// Time Complexity : O(N + E)

bool dfsOfGraph(vector<int> adj[],int vis[],int i,int par)
{
    vis[i] = 1;
    for(auto j : adj[i])
    {
        if(!vis[j])
        {
            if(dfsOfGraph(adj,vis,i,-1)) return true;
        }
        else if(j != par) return true;
    }
    return false;
}

bool dfs(vector<int> adj[],int n)
{
    int vis[n+1] = {0};
    for(int i = 1; i <= n; i++)
    {
        if(!vis[i])
        {
            if(dfsOfGraph(adj,vis,i,-1)) return true;
        }
    }
    return false;
}

int main()
{
    int n,m;
    cin >> n >> m;

    vector<int> adj[n+1];

    for(int i = 0; i < m; i++)
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);

        // If this is a undirected Graph
        adj[v].push_back(u);
    }

    if(dfs(adj,n)) cout << "Cycle Found" << endl;
    else cout << "Cycle Not Found" << endl;

    return 0;
}