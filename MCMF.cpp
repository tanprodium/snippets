// MCMF
struct MCMF {
    int n;
    MCMF() {}
    MCMF(int _n) {
        n = _n;
    };

    struct Edge {
        int u, v;
        ll cap, cost;

        Edge() {}
        Edge(int _u, int _v, ll _cap, ll _cost): u(_u), v(_v), cap(_cap), cost(_cost) {}
    };

    vector<vector<int>> adj, cost, cap;
    vector<Edge> e;

    const ll INF = 1e18;

    void add_edge(int u, int v, ll cap, ll cost) {
        e.pub({u, v, cap, cost});
    }

    void spfa(int s, vector<ll> &d, vector<ll> &p) {
        d.assign(n + 5, INF);
        d[s] = 0;
        vector<bool> inq(n + 5, false);
        queue<int> que;
        que.push(s);
        p.assign(n + 5, -1);

        while (!que.empty()) {
            int u = que.front();
            que.pop();
            inq[u] = false;
            for (int v : adj[u]) {
                if (cap[u][v] > 0 && d[v] > d[u] + cost[u][v]) {
                    d[v] = d[u] + cost[u][v];
                    p[v] = u;
                    if (!inq[v]) {
                        que.push(v);
                        inq[v] = true;
                    }
                }
            }
        }
    }

    ll min_cost_flow(int s, int t, ll K) {
        adj.assign(n + 5, vector<int>());
        cost.assign(n + 5, vector<int>(n + 5, 0));
        cap.assign(n + 5, vector<int>(n + 5, 0));
        for (Edge taken : e) {
            int u = taken.u, v = taken.v;
            ll t_cost = taken.cost, t_cap = taken.cap;
            adj[u].pub(v);
            adj[v].pub(u);
            cost[u][v] = t_cost;
            cost[v][u] = -t_cost;
            cap[u][v] = t_cap;
        }

        ll flow = 0;
        ll cost = 0;
        vector<ll> d, p;
        while (flow < K) {
            spfa(s, d, p);
            if (d[t] == INF) {
                break;
            }

            ll f = K - flow;
            int v = t;
            while (v != s) {
                int u = p[v];
                minimize(f, cap[u][v]);
                v = u;
            }
            //cout << f << ' ' << d[t] << '\n';

            flow += f;
            cost += f * d[t];
            v = t;
            while (v != s) {
                int u = p[v];
                cap[u][v] -= f;
                cap[v][u] += f;
                v = u;
            }
        }

        if (flow < K)
            return (-1);
        else return (cost);
    }
};
