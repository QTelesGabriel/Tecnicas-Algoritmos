bool visitado[N + 1];

void dfs(int u) {
    visitado[u] = true;
    for(auto[v, w]: G[u]) {
        if(!visitado[v]) {
            dfs(v);
        }
    }
}