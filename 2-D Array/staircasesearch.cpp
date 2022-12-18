#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
// Stair Case Algorithm
// We are traversing the matrix from top right
// If we are founding an element lesser than target we will move down
// else if we found greater element we will move left
// if we found target we will return its row and column
// Time Complexity : O(N+M)
// Space Complexity : O(1)
pair<int,int> StairCaseSearch(int arr[][100],int n,int m,int target)
{
    if(target<arr[0][0] || target>arr[n-1][m-1]) return {-1,-1};
    int r=0,c=m-1;
    while(r<m && c>=0)
    {
        if(arr[r][c]==target) return {r+1,c+1};
        if(arr[r][c]>target) c--;
        if(arr[r][c]<target) r++;
    }
    return {-1,-1};
}


int main()
{
    int arr[][100] = {{1,2,3,4},
                      {5,6,7,8},
                      {9,10,11,12},
                      {13,14,15,16}
                   };
    int n=4,m=4;
    pair<int,int> ans = StairCaseSearch(arr,n,m,7);
    cout<<"("<<ans.first<<","<<ans.second<<")"<<endl;
    return 0;
}