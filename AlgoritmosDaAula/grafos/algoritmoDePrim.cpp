// Usado para encontrar a Árvore Gerador Mínima (MST)

typedef tuple<int, int, int> tiii;

vector<pair<int, int>> prim(int origem) {
    priority_queue<tiii, vector<tiii>, greater<tiii>> pq;
    vector<pair<int, int>> mst;
    vector<bool> visitado(N + 1, false);

    pq.push({0, origem, origem});
    while(!pq.empty()) {
        auto [p, u, v] = pq.top();
        pq.pop();
        if(visitado[v]) {
            continue;
        }
        visitado[v] = true;
        mst.push_back({u, v});
        for(auto [r, w] : G[v]) {
            if(!visitado[r]) {
                pq.push({w, v, r});
            }
        }
    }

    return mst;
}