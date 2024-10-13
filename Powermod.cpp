// power MOD
template<class X, class Y>
    X power(const X &x, const Y &y) {
        assert(y >= 0);
        X a = x % MOD, res = 1;
        Y b = y;
        while (b > 0) {
            if (b & 1) {
                res *= a;
                res %= MOD;
            }
            a *= a;
            a %= MOD;
            b >>= 1;
        }
        return (res);
    }
