#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mod 1000000007

// Space Complexity : O(N + 2E)

int main()
{
    int n,m;
    cin >> n >> m;

    // If weight is not given
    vector<int> adj[n+1];

    // If Weight is given
    vector<pair<int,int>> adj2[n+1];

    for(int i = 0; i < m; i++)
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);

        // If this is a undirected Graph
        adj[v].push_back(u);
    }

    return 0;
}