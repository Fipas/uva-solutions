#include <bits/stdc++.h>

using namespace std;

int graph[101][101];
int nodes, edges;
bitset<101> maxBlackNodes;
int maxBlack = -1;

void backtrack(bitset<101> avail, int chosen, int black, bitset<101> blackNodes) {
    avail[chosen] = 1;
    blackNodes[chosen] = 1;

    for (int i = 1; i <= nodes; i++) {
        if (graph[chosen][i])
            avail[i] = 1;
    }

    for (int i = 1; i <= nodes; i++) {
        if (!avail[i]) 
            backtrack(avail, i, black + 1, blackNodes);
    }

    if (black > maxBlack) {
        maxBlack = black;
        maxBlackNodes = blackNodes;
    }
}

int main() {

    int TC;
    cin >> TC;

    while (TC--) {
        bitset<101> avail;
        bitset<101> nodesSet;
        bool first = true;
        memset(graph, 0, sizeof graph);
        maxBlackNodes.reset();
        maxBlack = -1;


        cin >> nodes >> edges;

        for (int i = 0; i < edges; i++) {
            int a, b;
            cin >> a >> b;
            graph[a][b] = 1;
            graph[b][a] = 1;
        }

        for (int i = 1; i <= nodes; i++) {
            backtrack(avail, i, 1, nodesSet);
        }

        cout << maxBlack << endl;
        for (int i = 1; i <= nodes; i++) {
            if (maxBlackNodes[i]) {
                if (first)
                    cout << i;
                else
                    cout << " " << i;
                first = false;
            }
        }
        cout << endl;
    }

    return 0;
}