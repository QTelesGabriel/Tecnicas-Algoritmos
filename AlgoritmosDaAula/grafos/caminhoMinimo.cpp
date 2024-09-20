vector<pair<int, int>> caminho_minimo(int origem, int destino) {
    vector<pair<int, int>> caminho;
    int v = destino;

    while(v != origem) {
        caminho.push_back({ predecessor[v], v });
        v = predecessor[v];
    }

    reverse(caminho.begin(), caminho.end());
    return caminho;
}