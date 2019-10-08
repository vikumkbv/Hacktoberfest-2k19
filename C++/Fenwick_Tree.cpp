struct BIT {
    vector<int> bit;
    int n, k;

    BIT(int n) : n(n), bit(n+1), k(ceil(log2(n))) {}

    void update(int i, int val) {
        while (i <= n) {
            bit[i] += val;
            i += (i & -i);
        }
    }

    int sum(int i) {
        int sum = 0;
        while (i > 0) {
            sum += bit[i];
            i -= (i & -i);
        }
        return sum;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l-1);
    }

    void build(vector<int> &a, int n) {
        for (int i = 1; i <= n; i++)
            update(i, a[i]);
    }

    int lower_bound(int v) {
        int sum = 0, pos = 0;
        for (int i = k; i >= 0; i--) {
            if(pos + (1 << i) <= n and sum + bit[pos + (1 << i)] < v) {
                sum += bit[pos + (1 << i)];
                pos += (1 << i);
            }
        }
        return pos + 1;
    }

    int upper_bound(int v) {
        int sum = 0, pos = 0;
        for (int i = k; i >= 0; i--) {
            if(pos + (1 << i) < n and sum + bit[pos + (1 << i)] <= v) {
                sum += bit[pos + (1 << i)];
                pos += (1 << i);
            }
        }
        return pos + 1;
    }
};
