/*
    To solve F(n) = a1 * F(n-1) + a2 * F(n-2) + ..... + ak * F(n-k)

                                                  n-k+1
    |   F(n)   |     |  a1 a2 a3 a4 a5 . . 0  ak |        | F(k-1) |
    |  F(n-1)  |     |  1  0  0  0  0  . . 0  0  |        | F(k-2) |
    |  F(n-2)  |     |  0  1  0  0  0  . . 0  0  |        | F(k-3) |
    |  F(n-3)  |  =  |  0  0  1  0  0  . . 0  0  |        | F(k-4) |
    |  F(n-4)  |     |  0  0  0  1  0  . . 0  0  |        | F(k-5) |
    |    ..    |     |  .  .  .  .  .  . . .  .  |        |   ..   |
    |    ..    |     |  .  .  .  .  .  . . .  .  |        |   ..   |
    | F(n-k+1) |     |  0  0  0  0  0  . . 1  0  |        |  F(0)  |
*/

// Check for overflow in multiply when changing to int
using type_t = long long;
struct Matrix {
    int n, m;
    vector<vector<type_t>> mat;

    Matrix(const vector<vector<type_t>> _mat) : n(_mat.size()), m(_mat[0].size()), mat(_mat) {}
    Matrix(int _n) : n(_n), m(_n), mat(vector<vector<type_t>>(_n, vector<type_t>(_n, 0))) {}
    Matrix(int _n, int _m) : n(_n), m(_m), mat(vector<vector<type_t>>(_n, vector<type_t>(_m, 0))) {}
    Matrix(int _n, int _m, type_t _val) : n(_n), m(_m), mat(vector<vector<type_t>>(_n, vector<type_t>(_m, _val))) {}
    Matrix(const Matrix &o) : n(o.n), m(o.m), mat(o.mat) {}

    // Remove modulo for doubles
    Matrix operator + (const Matrix &o) const {
        assert(n == o.n && m == o.m);
        vector<vector<type_t>> temp_mat(n, vector<type_t>(m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                temp_mat[i][j] = (mat[i][j] + o.mat[i][j]) % mod;
        return Matrix(move(temp_mat));
    }

    Matrix operator + (type_t &c) const {
        vector<vector<type_t>> temp_mat(n, vector<type_t>(m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                temp_mat[i][j] = (mat[i][j] + c) % mod;
        return Matrix(move(temp_mat));
    }

    Matrix operator - (const Matrix &o) const {
        assert(n == o.n && m == o.m);
        vector<vector<type_t>> temp_mat(n, vector<type_t>(m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                temp_mat[i][j] = (mat[i][j] - o.mat[i][j] + mod) % mod;
        return Matrix(move(temp_mat));
    }

    Matrix operator - (type_t &c) const {
        vector<vector<type_t>> temp_mat(n, vector<type_t>(m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                temp_mat[i][j] = (mat[i][j] - c + mod) % mod;
        return Matrix(move(temp_mat));
    }

    Matrix operator * (const Matrix &o) const {
        assert(m == o.n);
        int new_n = n, new_m = o.m, col = m;
        vector<vector<type_t>> temp_mat(new_n, vector<type_t>(new_m, 0));
        for (int i = 0; i < new_n; i++)
            for (int k = 0; k < col; k++) {
                for (int j = 0; j < new_m; j++) {
                    temp_mat[i][j] += 1LL * mat[i][k] * o.mat[k][j];
                    while (temp_mat[i][j] >= mod * mod) {
                        temp_mat[i][j] -= mod * mod;
                    }
                }
            }
        for (int i = 0; i < new_n; i++)
            for (int j = 0; j < new_m; j++)
                if (temp_mat[i][j] >= mod)
                    temp_mat[i][j] %= mod;
        return Matrix(move(temp_mat));
    }

    Matrix operator * (type_t &c) const {
        vector<vector<type_t>> temp_mat(n, vector<type_t>(m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                temp_mat[i][j] = (mat[i][j] * c) % mod;
        return Matrix(move(temp_mat));
    }

    Matrix operator / (type_t &c) const {
        type_t modinv = ::power(c, mod-2, mod);
        vector<vector<type_t>> temp_mat(n, vector<type_t>(m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                temp_mat[i][j] = (mat[i][j] * modinv) % mod;    // divide for doubles
        return Matrix(move(temp_mat));
    }

    Matrix operator - () {
        vector<vector<type_t>> temp_mat(n, vector<type_t>(m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
               temp_mat[i][j] = -mat[i][j];
        return Matrix(move(temp_mat));
    }

    Matrix power(ll y) {
        assert(n == m);
        Matrix x(*this), ans = Matrix::identity(n);
        while (y > 0) {
            if (y % 2) ans *= x;
            x *= x;
            y /= 2;
        }
        return ans;
    }

    Matrix transpose() {
        vector<vector<type_t>> temp_mat(m, vector<type_t>(n));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                temp_mat[j][i] = mat[i][j];
        return Matrix(move(temp_mat));
    }

    static Matrix identity(int _n) {
        vector<vector<type_t>> temp_mat(_n, vector<type_t>(_n, 0));
        for (int i = 0; i < _n; i++)
            temp_mat[i][i] = 1;
        return Matrix(move(temp_mat));
    }

    Matrix& fill(type_t &c) { mat = vector<vector<type_t>>(n, vector<type_t>(m, c)); return *this; }
    void clear() { mat = vector<vector<type_t>>(n, vector<type_t>(m, 0)); }

    Matrix& operator = (const Matrix &o) { this->mat = o.mat; this->n = o.n; this->m = o.m; return *this; }
    Matrix& operator += (const Matrix &o) { return *this = (*this + o); }
    Matrix& operator += (type_t &c) { return *this = (*this + c); }
    Matrix& operator -= (const Matrix &o) { return *this = (*this - o); }
    Matrix& operator -= (type_t &c) { return *this = (*this - c); }
    Matrix& operator *= (const Matrix &o) { return *this = (*this * o); }
    Matrix& operator *= (type_t &c) { return *this = (*this * c); }
    Matrix& operator /= (type_t &c) { return *this = (*this / c); }
    vector<type_t>& operator [] (int n) { return mat[n]; }
    bool operator == (const Matrix &o) const { return n == o.n && m == o.m && mat == o.mat; }
    bool operator != (const Matrix &o) const { return n != o.n || m != o.m || mat != o.mat; }
};

ostream& operator << (ostream &os, Matrix &v) { for (int i = 0; i < v.n; i++) for (int j = 0; j < v.m; j++) os << v[i][j] << " \n"[j == v.m - 1]; return os; }
