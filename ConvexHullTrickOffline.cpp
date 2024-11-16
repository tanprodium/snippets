struct Line {
    ll a, b, idx;

    Line(ll _a, ll _b, ll _idx) {
        a = _a;
        b = _b;
        idx = _idx;
    }

    ll cal(ll x, ll y) {
        return a * x + b * y;
    }

    bool operator < (const Line& z) const {
        if (a == z.a && b == z.b) {
            return idx > z.idx;
        }
        if (a == z.a) {
            return b < z.b;
        }
        return a < z.a;
    }
};

pair<ll, ll> find_ins(Line a, Line b) {
    ll z = (b.b - a.b), t = (a.a - b.a);
    return {z, t};
}

struct Convex_hull {
    vector<Line> a = {{ -1, -1, -1}};
    vector<Line> dq, dqp;
    ll rmq[N + 5][LOG + 2] = {0ll}, Log2[N + 5] = {0ll};
    void insert(Line z) {
        a.push_back(z);
    }

    Convex_hull() {}

    void precal() {
        sort(1 + all(a));
        for (ll i = 1; i < sz(a); ++i) {
            if (sz(dq) >= 2) {
                pair<ll, ll> z = find_ins(dq.back(), a[i]), t = find_ins(dq[sz(dq) - 2], dq.back());
                while (z.fi * t.se < z.se * t.fi) {
                    dq.pop_back();
                    if (sz(dq) < 2) {
                        break;
                    }
                    z = find_ins(dq.back(), a[i]), t = find_ins(dq[sz(dq) - 2], dq.back());
                }
            }
            dq.push_back(a[i]);
        }
        for (ll i = 2; i <= sz(dq); ++i) {
            Log2[i] = 1 + Log2[i >> 1];
        }
        memset(rmq, 0x3f, sizeof rmq);
        for (ll i = 0; i < sz(dq); ++i) {
            rmq[i][0] = dq[i].idx;
        }
        for (ll k = 1; k <= LOG; ++k) {
            for (ll i = 0; i + (1 << k) - 1 < sz(dq); ++i) {
                rmq[i][k] = min(rmq[i][k - 1], rmq[i + (1 << (k - 1))][k - 1]);
            }
        }
    }

    ll get(ll l, ll r) {
        ll k = Log2[r - l + 1];
        return min(rmq[l][k], rmq[r - (1 << k) + 1][k]);
    }

    ll get_mx(ll x, ll y) {
        if (dq.empty()) {
            return -1;
        }
        ll l = 1, r = sz(dq) - 1;
        while (l <= r) {
            ll mid = (l + r) >> 1;
            ll z = dq[mid - 1].cal(x, y), t = dq[mid].cal(x, y);
            if (z <= t) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        l--;
        ll z = dq[l].cal(x, y), R = l;
        l = 0, r = R;
        while (l <= r) {
            ll mid = (l + r) >> 1;
            ll t = dq[mid].cal(x, y);
            if (t == z) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        r++;
        ll L = r;
        assert(L <= R);
        // cout << L << " " << R << " " << z << '\n';
        return get(L, R);
    }
};
