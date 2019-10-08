const int N = 1e3;
int mat[N][N], dist[N][N];
int n;
// Give infinity if no edge
// mat[i][j] denotes directed edge from i to j

void FloydWarshall() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if (i == j) {
                dist[i][j] = 0;
            } else {
                dist[i][j] = mat[i][j];
            }
        }
    }

    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}
