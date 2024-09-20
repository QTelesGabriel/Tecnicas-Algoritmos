bool visitado[N + 1];
bool em_visitacao[N + 1];

bool detecta_ciclos() {
    for(int u = 1; u <= N; u++) {
        if(dfs(u)) {
            return true;
        }
    }

    return false;
}

bool dfs(int u) {
    if(em_visitacao[u]) return true;
    if(visitado[u]) return false;

    em_visitacao[u] = visitado[u] = true;

    for(auto v : G[u]) {
        if(dfs(v)) {
            return true;
        }
    }

    em_visitacao[u] = false;
    return false;
}