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

// GraphEdge
struct Edge {
    int u, v, w;

    Edge() {}
    Edge(int _u, int _v, int _w = 0): u(_u), v(_v), w(_w) {}

    // operator definition

    bool operator < (const Edge &other) const {
        return (w < other.w);
    }
};

struct EulerianCircuit {
    int n;
    vector<vi> adj;
    vector<Edge> e;
    vi ret;
    EulerianCircuit() {}
    EulerianCircuit(int _n) {
        n = _n;
        adj.resize(n + 5);
    }
    void add_edge(int u, int v) {
        adj[u].pub(sz(e));
        adj[v].pub(sz(e));
        e.eb(u, v, 0);
    }
    void dfs(int u) {
        for (int id : adj[u]) {
            int v = e[id].u ^ e[id].v ^ u;
            int w = e[id].w;
            if (w == 1) continue;
            e[id].w = 1;
            dfs(v);
        }
        ret.pub(u);
    }
    vi get() {
        ret.clear();
        dfs(1);
        return (ret);
    }
};

void solve() {
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t = 1;
    cin >> t;

    while (t--) solve();
    return 0;
}
