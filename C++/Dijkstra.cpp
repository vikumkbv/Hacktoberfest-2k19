using T = long long;
const int N = 2e5 + 10;
const T inf = numeric_limits<T>::max();
T dist[N];
bool done[N] = {false};
vector<pair<T, int>> graph[N];

// add directed edge from u to v with distance d
void add_edge(int u, int v, T d) {
    graph[u].emplace_back(d, v);
}

// first element stores distance, second stores the location
void dijkstra(int src) {
    fill(dist, dist+N, inf);
    dist[src] = 0;
    priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> q;
    q.emplace(0, src);

    while (!q.empty()) {
        int u, d;  // u : vertex with min dist, d : min dist
        tie(d, u) = q.top(); q.pop();

        if(done[u]) continue;
        done[u] = true;

        for(pair<T, int>& v : graph[u]) {
            if(v.first + d < dist[v.second]) {
                dist[v.second] = v.first + d;
                q.emplace(dist[v.second], v.second);
            }
        }
    }
}
