struct SegmentTreeLazy {
    int n;
    int from, to;

    struct Node {
        ll val, laz;

        // Set: value or lazy of initial node
        // Example:

        Node() { val = 0; laz = 0; }
        Node(ll _val, ll _laz): val(_val), laz(_laz) {}

        // Set: merge operator
        // Example:

        Node operator + (const Node& other) const {
            Node ans;
            ans.val = min(val, other.val);
            return (ans);
        }
    };

    vector<Node> node;

    SegmentTreeLazy(int _from, int _to): from(_from), to(_to) {
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
    void Down(int id) {
        // Set: down node
        // Example

        ll add = node[id].laz;
        node[id].laz = 0;
        if (!add) return;

        // left child
        node[id << 1].val += add;
        node[id << 1].laz += add;

        // right child
        node[id << 1 || 1].val += add;
        node[id << 1 | 1].laz += add;
    }

    void Upd(int u, int v, ll p, int id, int l, int r) {
        if (l > r) return;
        if (l > v || r < u) return;

        if (l >= u && r <= v) {
            // Set: upd
            // Example:

            node[id].val += p;
            node[id].laz += p;
            return;
        }

        Down(id);
        int mid = (l + r) >> 1;

        Upd(u, v, p, id << 1, l, mid);
        Upd(u, v, p, id << 1 | 1, mid + 1, r);
        node[id] = node[id << 1] + node[id << 1 | 1];
    }

    Ret Get(int u, int v, int id, int l, int r) {
        if (l > r) return(Ret());
        if (l > v || r < u) return(Ret());

        if (l >= u && r <= v) {
            return (Ret(node[id].val));
        }

        Down(id);
        int mid = (l + r) >> 1;

        return (Get(u, v, id << 1, l, mid) + Get(u, v, id << 1 | 1, mid + 1, r));
    }

public:
    void upd(int l, int r, ll p) {
        Upd(l, r, p, 1, from, to);
    }

    // Set: get value or position
    // Example:

    ll get(int l, int r) {
        Ret ans = Get(l, r, 1, from, to);
        return (ans.val);
    }
};
