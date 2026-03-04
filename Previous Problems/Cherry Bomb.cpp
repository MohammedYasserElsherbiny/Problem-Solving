#include <bits/stdc++.h>
#include <map>           // Fixed: Added map header
#include <unordered_map>
#include <unordered_set>

using namespace std;

#define sherb ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
typedef long long ll; 
typedef long double ld;
typedef unsigned long long ull; // Fixed: Removed non-breaking space
typedef vector<int> vi;
typedef vector<long long> vl;

#define all(x) x.begin(), x.end()
#define si(x) (ll(x.size()))
#define For(i, j, n) for(ll i = j; i < n; i++)
#define rFor(i, j, n) for(ll i = j; i >= n; i--)
#define read(a) for(ll i = 0; i < (ll)a.size(); i++) cin >> a[i];
#define readd(a) For(i, 0, si(a)) For(j, 0, si(a[0])) cin >> a[i][j];
#define F first
#define S second
#define SQ(a) (a)*(a)

// Helper functions
ll gcd(ll n1, ll n2) {
    while (n1 != 0 && n2 != 0) {
        n1 %= n2;
        swap(n1, n2);
    }
    return max(n1, n2);
}

ll lcm(ll n1, ll n2) {
    if (n1 == 0 || n2 == 0) return 0;
    return abs(n1 * n2) / gcd(n1, n2);
}

ll power(ll a, ll b) {
    ll result = 1;
    while (b) {
        if (b & 1) result = (result * a);
        a = (a * a);
        b >>= 1;
    }
    return result;
}

int main() {
    sherb;
    
    int tt = 1;
    cin >> tt; 

    while (tt--) {
        int n, k;
        cin >> n >> k;

        vector<int> a(n), b(n);
        map<int, int> mp;
        
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++) cin >> b[i];

        int cnt = 0, val;
        for(int i = 0; i < n; i++) {
            if(b[i] != -1) {
                cnt++;
                mp[a[i] + b[i]]++;
                val = a[i] + b[i];
            }
        }
        
        if(cnt == 0) {
            cout << k + 1 - (*max_element(all(a)) - *min_element(all(a))) << '\n';
        } 
        else
        {
            if(mp.size() > 1)
                cout << "0\n";
            else
            {
                int f = 1;
                for(int i = 0; i < n; i++)
                {
                    if(f && val - a[i] > k || val - a[i] < 0)
                    {
                        f = 0;
                        cout << "0\n";
                        break;
                    }
                }
                if(f)
                    cout << "1\n";
            }
        }
    }

    return 0;
}