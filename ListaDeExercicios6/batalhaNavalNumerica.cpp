#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, v;

    cin >> n >> m;

    vector<int, pair<int, int>> vetor;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> v;
            vetor.push_back(v, {i, j});
        }
    }

    int l = 0; r = vetor.size() - 1;

    while(l < r) {
        int mid = (vetor[l].first + vetor[r].first) / 2;
    }

    return 0;
}