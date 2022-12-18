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

ll binpow(ll a, ll b)
{
	ll ans = 1;
	while (b > 0)
	{
		if ((b & 1) == 1) ans *= a;
		a *= a;
		b = b >> 1;
	}
	return ans;
}

ll gcd(ll a, ll b)
{
	if (b == 0) return a;
	return gcd(b, a % b);
}

ll lcm(ll a, ll b)
{
	return (a / gcd(a, b)) * b;
}

struct fenwick {

    vector<int> fn;
    int n;

    void init(int n) {

        this->n = n + 1;
        fn.resize(this->n, 0);

    }

    void add(int x, int y) {

        x++; // 1 Based Indexing

        while (x < n) {
            fn[x] += y;
            x += (x & (-x));
        }
    }

    int sum(int x) {
        x++; // 1 Based Indexing

        int ans = 0;
        while (x) {
            ans += fn[x];
            x -= (x & (-x));
        }

        return ans;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }
};


void solve()
{
	int n;
	cin >> n;
	pair<int, int> arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i].first;
		arr[i].second = i;
	}

	fenwick tree;
	tree.init(n);

	sort(arr, arr + n);

	int inversionCount = 0;
	for(int i = 0; i < n; i++) {
		int value = arr[i].first;
		int index = arr[i].second;

		inversionCount += tree.sum(index + 1, n - 1);
		tree.add(index, 1);
	}

	cout << inversionCount << endl;
}

int main()
{
	file();
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t = 1;
	// cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}