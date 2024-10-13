// include
#include<bits/stdc++.h>

using namespace std;

// random
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// templates
template<class X, class Y>
    bool maximize(X &x, const Y &y) {
        if (y > x) {
            x = y;
            return (true);
        } else return (false);
    }

template<class X, class Y>
    bool minimize(X &x, const Y &y) {
        if (y < x) {
            x = y;
            return (true);
        } else return (false);
    }

// define
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define eb emplace_back

// another define
using pii = pair<int, int>;
using ll  = long long;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;

// limit
const int oo = 2e9;

void solve() {

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t = 1;
    //cin >> t;

    while (t--) solve();
    return 0;
}
