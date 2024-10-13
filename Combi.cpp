// Combination
vector<ll> fact;
vector<ll> ifact;

ll C(int n, int r) {
    if (n < r | r < 0) return (0ll);
    if (!sz(fact)) fact.pub(1);
    if (!sz(ifact)) ifact.pub(1);
    while (sz(fact) < n + 1) {
        fact.pub(fact.back() * sz(fact) % MOD);
        ifact.pub(power(fact.back(), MOD - 2));
    }
    return (fact[n] * ifact[n - r] % MOD * ifact[r] % MOD);
}
