// RoundUpSeg
vector<pll> RoundUpSeg(ll X) {
    vector<pll> ret;
    int r = X;
    while (r > 0) {
        ll d = (X + r - 1) / r;
        ll l = (X + d - 1) / d;
        ret.pub({l, r});
        r = l - 1;
    }
    reverse(all(ret));
    return (ret);
}
