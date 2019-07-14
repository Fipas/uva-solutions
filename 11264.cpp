#include <bits/stdc++.h>

using namespace std;


int main() {

    int TC;
    cin >> TC;

    while (TC--) {
        int numCoins;
        vector<int> coins;
        int maxCoins = 1;
        int maxSum = 0;

        cin >> numCoins;
        coins.resize(numCoins);

        if (numCoins > 1)
            maxCoins++;

        for (int i = 0; i < numCoins; i++)
            cin >> coins[i];

        maxSum = coins[0];
        for (int i = 1; i < numCoins - 1; i++) {
            //cout << maxSum << endl;
            if (maxSum + coins[i] < coins[i + 1]) {
                maxSum += coins[i];
                maxCoins++;
            }
        }

        //cout << endl;
        cout << maxCoins << endl;
    }

    return 0;
}