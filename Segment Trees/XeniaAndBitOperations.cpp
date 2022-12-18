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

	void BuildTree(int arr[],int ind,int low,int high,int count,int n) {
		if(low == high) {
			seg[ind] = arr[low];
			return;
		}
		int mid = low + (high - low)/2;
		BuildTree(arr,2*ind + 1,low,mid,count + 1,n);
		BuildTree(arr,2*ind + 2,mid + 1,high,count + 1,n);
		if((n - count) % 2 == 0) {
			seg[ind] = seg[2*ind + 1] ^ seg[2*ind + 2];
		} else {
			seg[ind] = seg[2*ind + 1] | seg[2*ind + 2];
		}
	}

	int query()
	{
		return seg[0];
	}

	void update(int ind,int low,int high,int i,int val,int count,int n)
	{
		if(low == high) {
			seg[ind] = val;
			return;
		}

		int mid = low + (high - low)/2;

		if(i <= mid) update(2*ind + 1,low,mid,i,val,count + 1,n);
		else update(2*ind + 2,mid + 1,high,i,val,count + 1,n);

		if((n - count) % 2 == 0) {
			seg[ind] = seg[2*ind + 1] ^ seg[2*ind + 2];
		} else {
			seg[ind] = seg[2*ind + 1] | seg[2*ind + 2];
		}
	}
};

ll binpow(ll a,ll b)
{
    ll ans = 1;
    while(b > 0)
    {
        if((b & 1) == 1) ans *= a;
        a *= a;
        b = b >> 1;
    }
    return ans;
}

ll gcd(ll a,ll b)
{
	if(b == 0) return a;
	return gcd(b, a%b);
}

ll lcm(ll a,ll b)
{
	return (a / gcd(a,b)) * b;
}

void solve()
{
	int n,q;
	cin >> n >> q;
	int size = pow(2,n);
	int arr[size];
	for(ll i = 0; i < size; i++) cin >> arr[i];
	SegmentTree st(size);
	st.BuildTree(arr,0,0,size - 1,0,n);
	for (int i = 0; i < q; ++i)
	{
		ll ind,val;
		cin >> ind >> val;
		st.update(0,0,size - 1,ind - 1,val,0,n);
		cout << st.query() << endl;
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