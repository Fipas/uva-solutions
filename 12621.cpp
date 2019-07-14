#include <bits/stdc++.h>

using namespace std;

int table[110][255];
int capacity;
vector<int> itens;

int take(int id, int rem) {
	//cout << id << "\t" << rem << endl;
	if (rem >= capacity) {
		//cout << "tois1\n";
		return rem;
	}
	if (id == itens.size()) {
		//cout << "tois2\n";
		return 1000000000;
	}
	if (table[id][rem] != 1000000000) {
		//cout << "tois3\n";
		return table[id][rem];
	}
	return (table[id][rem] = min(take(id + 1, rem), take(id + 1, rem + itens[id])));
}

int main() {
	int test;

	cin >> test;

	while (test--) {

		for (int i = 0; i < 110; i++) {
			for (int j = 0; j < 255; j++)
				table[i][j] = 1000000000;
		}

		int numItens;

		cin >> capacity >> numItens;
		capacity /= 10;
		itens.resize(numItens);

		for (int i = 0; i < numItens; i++) {
			cin >> itens[i];
			itens[i] /= 10;
		}


		take(0, 0);

		/*for (int i = 0; i < numItens; i++) {
			for (int j = 0; j < capacity; j++) {
				cout << table[i][j];
			}
			cout << endl;
		}*/

		//cout << table[0][0] << endl;

		if (table[0][0] == 1000000000)
			cout << "NO SOLUTION\n";
		else
			cout << table[0][0] * 10 << endl;

	}

	return 0;
}