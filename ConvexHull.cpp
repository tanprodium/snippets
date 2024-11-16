// ConvexHull
struct ConvexHull {
    struct Point {
        ll x, y;
        Point() {}
        Point(ll _x, ll _y): x(_x), y(_y) {}

        Point operator + (const Point &other) const {
            Point ret = {x + other.x, y + other.y};
            return (ret);
        }

        Point operator - (const Point &other) const {
            Point ret = {x - other.x, y - other.y};
            return (ret);
        }

        ll operator * (const Point &other) const {
            return (x * other.y - y * other.x);
        }

        bool operator < (const Point &other) const {
            if (x == other.x) {
                return (y < other.y);
            } else return (x < other.x);
        }
    };

    ll ccw(Point &A, Point &B, Point &C) {
        return ((B - A) * (C - A));
    }

    ll areax2(Point &A, Point &B, Point &C) {
        return (abs(ccw(A, B, C)));
    }

    ll dist2(Point &A, Point &B) {
        return ((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
    }

    // limit
    const ll oo = 1e18;

    // memory
    vector<Point> p, cv;
    ConvexHull() {}
    ConvexHull(vector<Point> _p): p(_p) {}

    void build_cv() {
        int n = sz(p);
        sort(all(p));
        sort(p.begin() + 1, p.end(), [&](Point &A, Point &B) {
            ll c = ccw(p[0], A, B);
            if (c == 0) {
                return (dist2(p[0], A) < dist2(p[0], B));
            }
            return (c < 0);
        });
        int i = n - 1;
        while (i >= 0 && ccw(p[0], p[i], p.back()) == 0) --i;
        reverse(p.begin() + i + 1, p.end());
        cv.pub(p[0]);
        for (int i = 1; i < n; i++) {
            while (sz(cv) >= 2 && (cv[sz(cv) - 1] - cv[sz(cv) - 2]) * (p[i] - cv[sz(cv) - 2]) > 0)
                cv.pob();
            cv.pub(p[i]);
        }
    }

    bool inside(Point X) {
        int l = 1, r = sz(cv) - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (ccw(cv[0], cv[mid], X) <= 0)
                l = mid + 1;
            else r = mid - 1;
        }
        if (l >= sz(cv)) {
            return (false);
        }
        Point A = cv[l - 1], B = cv[min(sz(cv) - 1, l)], C = cv[0];
        ll XAB = areax2(X, A, B);
        ll XBC = areax2(X, B, C);
        ll XAC = areax2(X, A, C);
        ll ABC = areax2(A, B, C);
        if (XAB + XBC + XAC == ABC)
            return (true);
        else return (false);
    }
};
