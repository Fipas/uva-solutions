#include <bits/stdc++.h>

using namespace std;


int main() {

    int TC;
    cin >> TC;

    while (TC--) {
        int n;
        vector<int> column;
        int board[8][8];

        cin >> n;
        column.resize(n);

        for (int i = 0; i < n; i++) {
            column[i] = i;
            for (int j = 0; j < n; j++)
                cin >> board[i][j];
        }


        int sum = 10000;

        do {
            int actSum = 0;
            for (int i = 0; i < n; i++) {
                actSum += board[i][column[i]];
            }
            sum = min(sum, actSum);
        } while (next_permutation(column.begin(), column.end()));

        cout << sum << endl;

    }

    return 0;
}