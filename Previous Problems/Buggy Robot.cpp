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
#define read(a) for(ll i = 0; i < si(a); i++) cin >> a[i];
#define readd(a) For(i, 0, si(a)) For(j, 0, si(a[0])) cin >> a[i][j];
#define F first
#define S second
#define SQ(a) (a)*(a)

int const N = 65545;

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

bool inbound(int i, int j, int n, int m)
{
    return i < n && i > -1 && j < m && j > -1;
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
        int n, m;
        cin >> n;

        int dir[2] = {0};

        string str;
        cin >> str;

        For(i, 0, sz(str))
        {
            int move1 = 0, move2 = 0;

            if(str[i] == 'U') dir[0]--;
            if(str[i] == 'D') dir[0]++;
            if(str[i] == 'L') dir[1]--;
            if(str[i] == 'R') dir[1]++;
        }

        cout << n - (abs(dir[0]) + abs(dir[1]));
    }

    return 0;
}




/*


https://codeforces.com/group/fOSxgJrX1P/contest/662228/problem/M

*/