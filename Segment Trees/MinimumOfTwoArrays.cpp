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
	int n1,n2,q;
	cin >> n1 >> n2 >> q;
	int arr[n1];
	int brr[n2];
	for(int i = 0; i < n1; i++) cin >> arr[i];
	for(int i = 0; i < n2; i++) cin >> brr[i];
	SegmentTree st1(n1);
	SegmentTree st2(n2);
	st1.BuildTree(arr,0,0,n1 - 1);
	st2.BuildTree(brr,0,0,n2 - 1);

	for (int i = 0; i < q; ++i)
	{
		int type;
		cin >> type;
		if(type == 1) {
			int l1,r1,l2,r2;
			cin >> l1 >> r1 >> l2 >> r2;

			cout << min(st1.query(0,arr,l1,r1,0,n1 - 1),st2.query(0,brr,l2,r2,0,n2 - 1)) << endl;
		} else {
			int a,ind,val;
			cin >> a >> ind >> val;

			if(a == 1) {
				st1.update(ind,val,arr,0,n1 - 1,0);
				arr[ind] = val;
			} else {
				st2.update(ind,val,brr,0,n2 - 1,0);
				brr[ind] = val;
			}
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