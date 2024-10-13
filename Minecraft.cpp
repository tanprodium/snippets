// include
#include<bits/stdc++.h>

using namespace std;

// define
#define fi    first
#define se    second

#define pub   push_back
#define pob   pop_back
#define puf   push_front
#define pof   pop_front
#define eb    emplace_back
#define upb   upper_bound
#define lwb   lower_bound

#define left  VAN
#define right TAN

#define sz(a)               (int)a.size()
#define all(a)              (a).begin(),(a).end()
#define rall(a)             (a).begin(),(a).end()
#define sort_and_unique(a)  sort(all(a));(a).resize(unique(all(a))-a.begin())
#define max_                max_element
#define min_                min_element

// another define
using ll  = long long;
using ld  = long double;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
using mii = map<int, int>;
using mil = map<int, ll>;
using mli = map<ll, int>;
using mll = map<ll, ll>;
using vi  = vector<int>;
using vl  = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using vpii = vector<pii>;

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

template<class T>
    void print(const T &a, const int &l, const int &r) {
        for (int i = l; i <= r; i++)
            cout << a[i] << ' ';
        cout << '\n';
    }

// limit
const int oo = 2e9;

// function
void yesno(bool x) {
    cout << (x ? "YES\n" : "NO\n");
}

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    reverse(all(s));
    vi c(k, 0);
    for (int i = 1; i <= n; i++) {
        string t;
        cin >> t;
        reverse(all(t));
        for (int j = 0; j < k; j++)
            if (t[j] == '1')
                ++c[j];
    }
    vector<vpii> t(k + 5, vpii(n, {-1, -1}));
    t[k][0] = {0, 0};
    for (int i = k; i; i--)
    for (int j = 0; j < n; j++) if (t[i][j].fi != -1) {
        int ni = i - 1;
        int nj = 2 * j;
        if (s[i - 1] == '1')
            ++nj;
        for (int b = 0; b <= 1; b++) {
            int njj = nj;
            if (!b) njj -= c[i - 1];
            else njj -= n - c[i - 1];
            if (njj < n && njj >= 0) {
                t[ni][njj] = {j, b};
            }
        }
    }
    if (t[0][0].fi == -1) {
        cout << -1 << '\n';
        return;
    }
    int j = 0;
    string ans = "";
    for (int i = 0; i < k; i++) {
        ans += char(t[i][j].se + '0');
        j = t[i][j].fi;
    }
    reverse(all(ans));
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t = 1;
    cin >> t;

    while (t--) solve();
    return 0;
}
