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
	int *lazy;
	public :

	SegmentTree(int n) {
		seg = new int[4*n + 1];
		lazy = new int[4*n + 1];
	}

	void BuildTree(int arr[],int i,int low,int high) {
		if(low == high) {
			seg[i] = arr[low];
			return;
		}

		int mid = low + (high - low)/2;

		BuildTree(arr,2*i + 1,low,mid);
		BuildTree(arr,2*i + 2,mid+1,high);

		seg[i] = seg[2*i+1] + seg[2*i+2];
	}

	int query(int ind,int arr[],int l,int r,int low,int high)
	{
		if(lazy[ind] != 0) {

			seg[ind] = (high - low + 1) - seg[ind];

			if(low != high) {
				lazy[2*ind + 1] += 1;
				lazy[2*ind + 1] %= 2;
				lazy[2*ind + 2] += 1;
				lazy[2*ind + 2] %= 2;
			}
			lazy[ind] = 0;
		}

		if(high < l || low > r) return 0;

		if(high <= r && low >= l) return seg[ind];

		int mid = low + (high - low)/2;

		int left = query(2*ind + 1,arr,l,r,low,mid);
		int right = query(2*ind + 2,arr,l,r,mid+1,high);
		return left + right;
	}

	void updateRange(int l,int r,int low,int high,int ind)
	{
		if(lazy[ind] != 0) {

			seg[ind] = (high - low + 1) - seg[ind];

			if(low != high) {
				lazy[2*ind + 1] += 1;
				lazy[2*ind + 1] %= 2;
				lazy[2*ind + 2] += 1;
				lazy[2*ind + 2] %= 2;
			}
			lazy[ind] = 0;
		}

		if(high < l || low > r) return;

		if(high <= r && low >= l) {
			seg[ind] = (high - low + 1) - seg[ind];
			if(low != high) {
				lazy[2*ind + 1] += 1;
				lazy[2*ind + 1] %= 2;
				lazy[2*ind + 2] += 1;
				lazy[2*ind + 2] %= 2;
			}
			return;
		}

		int mid = low + (high - low)/2;

		updateRange(l,r,low,mid,2*ind + 1);
		updateRange(l,r,mid + 1,high,2*ind + 2);

		seg[ind] = seg[2*ind + 1] + seg[2*ind + 2];
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
			int l,r;
			cin >> l >> r;

			st.updateRange(l,r,0,n - 1,0);
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