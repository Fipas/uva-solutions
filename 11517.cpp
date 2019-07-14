#include <bits/stdc++.h>

using namespace std;

int minCoins, ammount, numCoins;
vector<int> coins;
int table[10010][110];
int quantity[20010][110];

int ways(int sum, int coin) {
	if (sum <= 0) {
		return ammount - sum;
	}

	if (coin == numCoins) {
		return 1000000;
	}

	if (table[sum][coin] != -1) {
		return table[sum][coin];
	}

	int ans = min(ways(sum - coins[coin], coin + 1),
			      ways(sum, coin + 1));

	return table[sum][coin] = ans;
}

int tois(int sum, int coin) {	
	if (sum < 0)
		return 1000000;
	if (sum == 0)
		return 0;
	if (coin == numCoins)
		return 1000000;
	if (quantity[sum][coin] != -1)
		return quantity[sum][coin];

	int ans = min(1 + tois(sum - coins[coin], coin + 1),
				  tois(sum, coin + 1));

	return quantity[sum][coin] = ans;
}

int main() {
	//ios::sync_with_stdio(false);

	int TC;
	cin >> TC;

	while (TC--) {
		memset(table, -1, sizeof table);
		memset(quantity, -1, sizeof quantity);
		cin >> ammount >> numCoins;
		coins.resize(numCoins);

		for (int i = 0; i < numCoins; i++)
			cin >> coins[i];

		int a1 = ways(ammount, 0);
		int a2 = tois(a1, 0);

		cout << a1 << " " << a2 << endl;
	}

	return 0;
}