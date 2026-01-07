#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define sherb ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
typedef long long ll; 
typedef long double ld;
typedef unsigned  long long ull;
typedef vector<int> vi;
typedef vector<long long> vl;
#define all(x) x.begin(), x.end()
#define sz(x) ll(x.size())
#define For(i, j, n) for(ll i = j; i < n; i++)
#define rFor(i, j, n) for(ll i = j; i >= n; i--)
#define read(a) for(ll i = 0; i < sz(a); i++) cin >> a[i];
#define readd(a) For(i, 0, si(a)) For(j, 0, sz(a[0])) cin >> a[i][j];
#define F first
#define S second
#define SQ(a) (a)*(a)

int const N = 2e5 + 5;

// summation of x^2 from 1 to n => (n * (n + 1) * (2n + 1)) / 6
// summation of x^3 from 1 to n => ((n * (n + 1)) / 2)^2
// if the difference between any two consecutive numbers is constant  a+...+b = (n* (a + b)) / 2
// if the ratio between any two consecutive numbers is constant  a + ak + ak^2 + ... + b = (bk - a) / (k - 1)

ll gcd(ll n1, ll n2)
{
    while (n1 != 0 && n2 != 0)
    {
        n1 %= n2;
        swap(n1, n2);
    }

    return max(n1, n2);
}

ll lcm(ll n1, ll n2)
{
    return (n1 * n2) / gcd(n1, n2);
}

ll power(ll a, ll b)
{
    ll result = 1;
    while (b) {
        if (b & 1)
            result = (result * a);
        a = (a * a);
        b >>= 1;
    }
    return result;
}

int main()
{
    sherb;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int tt = 1;
    //cin >> tt;

    while (tt--)
    {
        int n, m, k;
        cin >> n >> m >> k;

        vector<pair<int, int>> range;
        vl vec(n), val, operation(m + 2, 0), sum(n + 2, 0);
        read(vec);


        For(i, 0, m)
        {
            int l, r, v;
            cin >> l >> r >> v;

            range.push_back({l, r});
            val.push_back(v);
        }

        while(k--)
        {
            int l, r;

            cin >> l >> r;

            operation[l]++;
            operation[r + 1]--;
        }

        For(i, 1, m + 1) operation[i] += operation[i - 1];

        For(i, 1, m + 1) val[i - 1] *= operation[i];

        For(i, 0, m ) 
        {
            sum[range[i].F] += val[i];
            sum[range[i].S + 1] -= val[i];
        }

        
        For(i, 1, n + 1) sum[i] += sum[i - 1];
        
        For(i, 0, n) cout << vec[i] + sum[i + 1] << ' ';

    }

    return 0;
}


/*

https://codeforces.com/group/fOSxgJrX1P/contest/662586/problem/F

*/