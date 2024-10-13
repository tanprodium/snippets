// FenwickTree
struct FenwickTree {
    vector<ll> ft;
    int from, to;

    FenwickTree() {}
    FenwickTree(int _from, int _to): from(_from), to(_to) {
        // set initial value

        ft.assign(to - from + 5, 0);
    }

private:
    void Upd(int p, ll v) {
        p = max(p, from);
        for (int j = p; j <= to; j += (j & (-j)))
            ft[j] += v;
    }

    ll Get(int p) {
        ll result = 0;
        p = min(p, to);
        for (int j = p; j >= from; j -= (j & (-j)))
            result += ft[j];
        return (result);
    }

public:
    void upd(int p, ll v) {
        Upd(p, v);
    }

    ll get(int p) {
        return (Get(p));
    }
};
