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
		seg = new int[4*n + 1];
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

	int query(int ind,int l,int r,int low,int high)
	{
		if(high < l || low > r) return 0;

		if(high <= r && low >= l) return seg[ind];

		int mid = low + (high - low)/2;

		int left = query(2*ind + 1,l,r,low,mid);
		int right = query(2*ind + 2,l,r,mid+1,high);
		return left + right;
	}

	void update(int i,int low,int high,int ind)
	{
		if(low == high) {
			seg[ind]--;
			return;
		}

		int mid = low + (high - low)/2;

		if(i <= mid) update(i,low,mid,2*ind + 1);
		else update(i,mid + 1,high,2*ind + 2);

		seg[ind] = seg[2*ind + 1] + seg[2*ind + 2];
	}
};

void solve()
{
	int n;
	cin >> n;
	int arr[n];
	for(int i = 0; i < n; i++) cin >> arr[i];
	int maxm = 0;
	for(int i = 0; i < n; i++) {
		maxm = max(maxm,arr[i]);
	}
	int freq[maxm + 1] = {0};
	for(int i = 0; i < n; i++) {
		freq[arr[i]]++;
	}
	SegmentTree st(maxm + 1);
	st.BuildTree(freq,0,0,maxm);

	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		st.update(arr[i],0,maxm,0);
		ans += st.query(0,1,arr[i] - 1,0,maxm);
		// cout << ans << endl;
	}
	cout << ans << endl;
}

int main()
{
	file();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t = 1;
	cin >> t;
	while(t--)
	{
		solve();
	}
	return 0;
}