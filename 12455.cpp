#include <bits/stdc++.h>

using namespace std;


int main() {

    int TC;
    cin >> TC;

    while (TC--) {
        int length, numBars;
        bool found = false;
        vector<int> bars;

        cin >> length >> numBars;

        bars.resize(numBars);

        for (int i = 0; i < numBars; i++) {
            cin >> bars[i];
        }

        for (int i = 0; i <= (1 << numBars) - 1 && !found; i++) {
            int sum = 0;
            for (int bit = 0; bit < 20; bit++) {
                if (i & (1 << bit))
                    sum += bars[bit];
                if (sum == length) {
                    found = true;
                    break;
                }
            }
        }

        if (found)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}