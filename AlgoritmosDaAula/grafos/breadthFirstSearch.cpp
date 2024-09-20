bool visitado[N + 1];

void bfs(int u) {
    queue<int> fila;
    fila.push(u);
    visitado[u] = true;

    while(!fila.empty()) {
        u = fila.front();
        fila.pop();

        for(auto [v, w] : G[u]) {
            if(!visitado[v]) {
                fila.push(v);
                visitado[v] = true;
            }
        }
    }
}

vector<int> dist(N + 1, oo);

void bfs(int u) {
    queue<int> fila;
    fila.push(u);
    dist[u] = 0;
    while(!fila.empty()) {
        u = fila.front();
        fila.pop();

        for(auto [v, w] : G[u]) {
            if(dist[v] == oo) {
                dist[v] = dist[u] + w;
                fila.push(v);
            }
        }
    }
}