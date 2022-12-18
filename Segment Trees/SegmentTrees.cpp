#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mod 1000000007

void file()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

class SegmentTree {
	int *seg;
	public :

	SegmentTree(int n) {
		// Maximum Size Of Tree could be 4n only
		seg = new int[4*n + 1];
	}

	// Time Complexity Of Build : O(4N) == O(N) !!!
	void BuildTree(int arr[],int i,int low,int high) {
		if(low == high) {
			seg[i] = arr[low];
			return;
		}

		int mid = low + (high - low)/2;

		// Left Child
		BuildTree(arr,2*i + 1,low,mid);
		// Right Child
		BuildTree(arr,2*i + 2,mid+1,high);
		// Minimum Of Two

		seg[i] = min(seg[2*i+1],seg[2*i+2]);
	}

	// Query Time Complexity : O(logN)
	int query(int ind,int arr[],int l,int r,int low,int high)
	{
		// No Overlap
		// l r low high or low high l r
		if(high < l || low > r) return INT_MAX;

		// Complete Overlap
		// l low high r
		if(high <= r && low >= l) return seg[ind];

		// Partial Overlap
		int mid = low + (high - low)/2;

		int left = query(2*ind + 1,arr,l,r,low,mid);
		int right = query(2*ind + 2,arr,l,r,mid+1,high);
		return min(left,right);
	}


	// Update Time Complexity : O(logN)
	void update(int i,int val,int arr[],int low,int high,int ind)
	{
		// If we found the required Node
		if(low == high) {
			seg[ind] = val;
			return;
		}

		int mid = low + (high - low)/2;

		// If required node is left to mid, 
		// Move To Left Child Else Move To Right Child
		if(i <= mid) update(i,val,arr,low,mid,2*ind + 1);
		else update(i,val,arr,mid + 1,high,2*ind + 2);

		// Since, One Of The Child's Value is Updated
		// We have to find minimum again !!!
		seg[ind] = min(seg[2*ind + 1],seg[2*ind + 2]);
	}
};

void solve()
{
	int n,q;
	cin >> n >> q;
	int arr[n];
	for(int i = 0; i < n; i++) cin >> arr[i];
	SegmentTree st(n);
	st.BuildTree(arr,0,0,n - 1);

	for (int i = 0; i < q; ++i)
	{
		int type;
		cin >> type;
		if(type == 1) {
			int l,r;
			cin >> l >> r;

			cout << st.query(0,arr,l,r,0,n-1) << endl;
		} else {
			int ind,val;
			cin >> ind >> val;

			st.update(ind,val,arr,0,n - 1,0);
			arr[ind] = val;

			for(int i = 0; i < n; i++) cout << arr[i] << " ";
			cout << endl;
		}
	}
}

int main()
{
	file();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t = 1;
	// cin >> t;
	while(t--)
	{
		solve();
	}
	return 0;
}