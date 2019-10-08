struct Hash {
    string s; int n;
    vector<int> hash, pow, inv;
    int base, mod;

    Hash(string s, int base = 31, int mod = 1e9 + 9) : s(s), base(base), mod(mod) {
        n = s.size();
        hash.resize(n); pow.resize(n); inv.resize(n);
        hash[0] = s[0] - 'a' + 1;
        pow[0] = inv[0] = 1;
        for (int i = 1; i < n; i++) {
            pow[i] = (1LL * base * pow[i-1]) % mod;
            inv[i] = power(pow[i], mod-2, mod);
            hash[i] = (hash[i-1] + (s[i] - 'a' + 1LL) * pow[i]) % mod;
        }
    }

    int get_hash(int l, int r) {
        assert(0 <= l && l <= r && r < n);
        return l == 0 ? hash[r] : (1LL * (hash[r] - hash[l-1] + mod) * inv[l]) % mod;
    }

    ll power(ll x, ll y, ll mod) {
        if (y == 0) return 1LL;
        if (y % 2) return ((x % mod) * power(x, y - 1, mod)) % mod;
        return power((x * x) % mod, y / 2, mod);
    }
};
