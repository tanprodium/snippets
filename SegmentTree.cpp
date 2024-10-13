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
const ll oo = 1e18;

// structs

// SegmentTree
struct SegmentTree {
    int n;
    int from, to;

    struct Node {
        ll val;

        // Set: value or lazy of initial node
        // Example:

        Node() { val = oo; }
        Node(ll _val): val(_val) {}

        // Set: merge operator
        // Example:

        Node operator + (const Node &other) const {
            Node ans;
            ans.val = min(val, other.val);
            return (ans);
        }
    };

    vector<Node> node;

    SegmentTree(int _from, int _to): from(_from), to(_to) {
        n = to - from + 1;
        node.resize(4 * n + 5);
    }

    struct Ret {
        ll val;
        int loc;

        // Set: value and location
        // Example:

        Ret() { val = oo; loc = -1; }
        Ret(ll _val, int _loc = -1): val(_val), loc(_loc) {}

        // Set: merge operator
        // Example:

        Ret operator + (const Ret &other) const {
            Ret ans;
            if (val < other.val) ans = *this;
            else ans = other;
            return (ans);
        }
    };

private:
    // Set initial elements
    // Example:
    void Build(int id, int l, int r, const vector<ll> &a) {
        if (l > r) return;
        if (l == r) {
            node[id] = {a[l - from]};
            return;
        }

        int mid = (l + r) >> 1;

        Build(id << 1, l, mid, a);
        Build(id << 1 || 1, mid + 1, r, a);
        node[id] = node[id << 1] + node[id << 1 | 1];
    }

    void Upd(int p, ll v, int id, int l, int r) {
        if (l > r) return;
        if (l > p || r < p) return;

        if (l == r) {
            node[id] = {v};
            return;
        }

        int mid = (l + r) >> 1;

        Upd(p, v, id << 1, l, mid);
        Upd(p, v, id << 1 | 1, mid + 1, r);
        node[id] = node[id << 1] + node[id << 1 | 1];
    }

    Ret Get(int u, int v, int id, int l, int r) {
        if (l > r) return (Ret());
        if (l > v || r < u) return (Ret());

        if (l >= u && r <= v) return (Ret(node[id].val));

        int mid = (l + r) >> 1;

        return (Get(u, v, id << 1, l, mid) + Get(u, v, id << 1 | 1, mid + 1, r));
    }

public:
    void init(const vector<ll> &a) {
        Build(1, from, to, a);
    }

    void upd(int p, ll v) {
        Upd(p, v, 1, from, to);
    }

    // Set value or position
    // Example

    ll get(int l, int r) {
        Ret ans = Get(l, r, 1, from, to);
        return (ans.val);
    }
};

/*void solve() {
    vector<ll> a;
    int n = 1000 - rng() % 100;

    for (int i = 1; i <= n; i++) {
        ll x = rng() % oo;
        a.pb(x);
    }

    SegmentTree it(0, (int)a.size() - 1);
    it.init(a);

    while (true) {
        int t = rng() % 2;
        if (t) {
            int p = rng() % n;
            ll x = rng() % oo;
            cout << t << ' ' << p << ' ' << x << '\n';
            it.upd(p, x);
            a[p] = x;
        } else {
            int l = rng() % n, r = rng() % n;
            if (l > r) swap(l, r);

            ll tmp1 = it.get(l, r);
            ll tmp2 = oo;

            for (int i = l; i <= r; i++) minimize(tmp2, a[i]);

            cout << t << ' ' << l << ' ' << r << '\n';

            if (tmp1 != tmp2) {
                cout << "Stop";
                return;
            }
        }
    }
}*/

int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(0); cout.tie(0);
    int t = 1;
    //cin >> t;

    while (t--) solve();
    return 0;
}
