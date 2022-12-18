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

struct info {
	int open,close,full;
	info(int _open,int _close,int _full) {
		open = _open;
		close = _close;
		full = _full;
	}
	info() {
		open = 0;
		close = 0;
		full = 0;
	}
};

class SegmentTree {
	info *seg;
	public :

	SegmentTree(int n) {
		seg = new info[4*n + 1];
	}

	void BuildTree(string &s,int ind,int low,int high) {
		if(low == high) {
			if(s[low] == '(') {
				seg[ind].open = 1;
				seg[ind].close = 0;
			} else {
				seg[ind].close = 1;
				seg[ind].open = 0;
			}
			seg[ind].full = 0;
			return;
		}

		int mid = (high + low)/2;
		BuildTree(s,2*ind + 1,low,mid);
		BuildTree(s,2*ind + 2,mid + 1,high);

		seg[ind].full = seg[2*ind + 1].full + seg[2*ind + 2].full + min(seg[2*ind + 1].open,seg[2*ind + 2].close);
		seg[ind].open = seg[2*ind + 1].open + seg[2*ind + 2].open - min(seg[2*ind + 1].open,seg[2*ind + 2].close);
		seg[ind].close = seg[2*ind + 1].close + seg[2*ind + 2].close - min(seg[2*ind + 1].open,seg[2*ind + 2].close);
	}

	info query(int ind,int l,int r,int low,int high) {
		if(low >= l && high <= r) return seg[ind];

		if(high < l || low > r) return (info(0,0,0));

		int mid = (high + low)/2;
		info left = query(2*ind + 1,l,r,low,mid);
		info right = query(2*ind + 2,l,r,mid + 1,high);

		int full = left.full + right.full + min(left.open,right.close);
		int open = left.open + right.open - min(left.open,right.close);
		int close = left.close + right.close - min(left.open,right.close);

		// cout << "Full : " <<  full << endl;
		return (info(open,close,full));
	}
};

void solve()
{
	string s;
	cin >> s;
	int n = s.size();
	SegmentTree st(n);
	st.BuildTree(s,0,0,n-1);
	int q;
	cin >> q;
	for (int i = 0; i < q; ++i)
	{
		int l,r;
		cin >> l >> r;
		l--; r--;
		info it = st.query(0,l,r,0,n - 1);
		// cout << it.open << " " << it.close << endl;
		cout << 2*it.full << endl;
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