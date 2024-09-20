// Neste código demonstrarei diversas formas de representar um grafo em C++
// 1) Matriz de adjacências
// 2) Lista de adjacências (Mais utilizada)
// 3) Lista de arestas

#include <iostream>
#include <vector>
#include <tuple>

#define N 6

using namespace std;

int main()
{
    cout << "Matriz de adjacências" << endl;
    int G1[N + 1][N + 1];
    for(int i = 0; i <= N; i++) {
        for(int j = 0; j <= N; j++) {
            G1[i][j] = 0;
        }
    }
    G1[1][2] = 2, G1[1][3] = 1, G1[1][4] = 8;
    G1[2][1] = 5, G1[2][4] = 7, G1[2][5] = 2;
    G1[3][1] = 3, G1[3][4] = 9, G1[3][6] = 4;
    G1[4][3] = 1;
    G1[5][2] = 3, G1[5][6] = 6;
    G1[6][4] = 5;

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            cout << G1[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl << endl;

    cout << "Lista de adjacências" << endl;
    vector<pair<int, int>> G2[] {
        {},
        { {2, 2}, {3, 1}, {4, 8} },
        { {1, 5}, {4, 7}, {5, 2} },
        { {1, 3}, {4, 9}, {6, 4} },
        { {3, 1} },
        { {2, 3}, {6, 6} },
        { {4, 5} }
    };

    for(int u = 1; u <= N; u++) {
        cout << u << ": ";
        for(auto[v, w]: G2[u]) {
            cout << "(" << v << ", " << w << ") ";
        }
        cout << endl;
    }

    cout << endl << endl;
    
    cout << "Lista de arestas" << endl;
    vector<tuple<int, int, int>> A {
        { 1, 2, 2 }, { 1, 3, 1 }, { 1, 4, 8 },
        { 2, 1, 5 }, { 2, 4, 7 }, { 2, 5, 2 },
        { 3, 1, 3 }, { 3, 4, 9 }, { 3, 6, 4 },
        { 4, 3, 1 }, { 5, 2, 3 }, { 5, 6, 6 },
        { 6, 4, 5 }
    };

    for(auto [u, v, w] : A) {
        cout << "(" << u << ", " << v << ", " << w << ") " << endl;
    }

    return 0;
}