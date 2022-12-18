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
    vector<int> v = {1, 2, 3, 4, 5, 6, 7};

    fenwick tree;
    tree.init(v.size());

    for (int i = 0; i < v.size(); i++) {
        tree.add(i, v[i]);
    }

    cout << tree.sum(0, 5) << endl;

    tree.add(3, -4);

    cout << tree.sum(0, 5) << endl;
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