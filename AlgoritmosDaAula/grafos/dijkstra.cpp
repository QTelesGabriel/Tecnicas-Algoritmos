void dijkstra(int origem) {
    memset(dist, INF, sizeof(dist));
    dist[origem] = 0;

    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> pq;
    pq.push({0, origem});

    while(!pq.empty()) {
        auto[d, u] = pq.top;
        pq.pop();
        if(d > dist[u]) {
            continue;
        }
        for(auto[v, w] : G[u]) {
            if(dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({ dist[v], v });
            }
        }
    }
}