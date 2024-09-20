int componentes_conectados() {
    int quantidade = 0;

    for(int u = 1; u <= N; u++) {
        if(!visitado[u]) {
            quantidade++;
            cout << "Componente " << quantidade << " a partir de " << u << endl;
            dfs(u);
        }
    }

    return quantidade;
}