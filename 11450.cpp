#include <bits/stdc++.h>

using namespace std;

int money, numGarments;
vector<vector<int> > garments;
int table[25][210];

int buy(int garment, int avail) {
	if (avail < 0) {
		return 201;
	}

	if (garment == numGarments) {
		return avail;
	}

	if (table[garment][avail] != -1)
		return table[garment][avail];

	int best = 201;
	for (int i = 0; i < garments[garment].size(); i++) {
		best = min(best, buy(garment + 1, avail - garments[garment][i]));
	}

	return table[garment][avail] = best;
}

int main() {
	//ios::sync_with_stdio(false);

	int TC;
	cin >> TC;

	while (TC--) {
		memset(table, -1, sizeof table);
		cin >> money >> numGarments;
		garments.resize(numGarments);

		for (int i = 0; i < numGarments; i++) {
			int quantity;
			cin >> quantity;
			garments[i].resize(quantity);

			for (int j = 0; j < quantity; j++) {
				cin >> garments[i][j];
			}
		}

		buy(0, money);

		if (table[0][money] == 201)
			cout << "no solution\n";
		else
			cout << money - table[0][money] << endl;
	}

	return 0;
}