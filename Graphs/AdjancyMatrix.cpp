#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mod 1000000007

// Space Complexity : O(N^2)

int main()
{
    int n , m;
    // n -> No Of Nodes
    // m -> No Of Vertices
    cin >> n >> m;

    // Adjacent Matrix
    int adj[n+1][n+1];

    for(int i = 0; i < m; i++)
    {
        int u,v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    return 0;
}