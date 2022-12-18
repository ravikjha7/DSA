#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mod 1000000007

// Space Complexity : O(N + 2E) + O(N) + O(N)
// Time Complexity : O(N + E)

void dfsOfGraph(vector<int> adj[],int vis[],vector<int>& ans,int i)
{
    ans.push_back(i);
    vis[i] = 1;
    for(auto j : adj[i])
    {
        if(!vis[j])
        {
            dfsOfGraph(adj,vis,ans,j);
        }
    }
}

vector<int> dfs(vector<int> adj[],int n)
{
    int vis[n+1] = {0};
    cout << "Jaduuu" << endl;
    vector<int> ans;
    for(int i = 1; i <= n; i++)
    {
        if(!vis[i])
        {
            dfsOfGraph(adj,vis,ans,i);
        }
    }
    return ans;
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

    vector<int> ans = dfs(adj,n);
    for(auto i : ans) cout << i << " ";
    cout << endl;

    return 0;
}