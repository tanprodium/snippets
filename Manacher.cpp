// Manacher
template<typename T>
vector<int> manacher_odd(T s) {
    int n = s.size();
    if (n == 0) {
        return vector<int>();
    }
    s = "$" + s + "^";
    vector<int> p(n + 2);
    int l = 1, r = 1;
    for(int i = 1; i <= n; i++) {
        p[i] = max(0, min(r - i, p[l + (r - i)]));
        while(s[i - p[i]] == s[i + p[i]]) {
            p[i]++;
        }
        if(i + p[i] > r) {
            l = i - p[i], r = i + p[i];
        }
    }
    return (vector<int>(begin(p) + 1, end(p) - 1));
}

template<typename T>
vector<int> manacher(const T &s) {
    string t;
    for(auto c: s) {
        t += string("#") + c;
    }
    auto res = manacher_odd(t + "#");
    return (vector<int>(begin(res) + 1, end(res) - 1));
}

/*
    use of Manacher
    With s[0...sz(s)-1]
    Call t is Manacher'array of s
    s[l..r] is palindome if t[l + r] >= r - l + 1
*/
