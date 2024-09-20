const int oo = 0x3f3f3f3f;
vector<int>dist(N + 1, oo);

void bfs_dists(int u) {
    queue<int> fila;
    fila.push(u);
    dist[u] = 0;
    
    while(!fila.empty()) {
        u = fila.front();
        fila.pop();
        
        for(auto v : G[u]) {
            if(dist[v] == oo) {
                fila.push(v);
                dist[v] = dist[u] + 1;
            }
        }
    }
}