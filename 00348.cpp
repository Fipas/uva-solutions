#include <bits/stdc++.h>

using namespace std;

vector<int> p;
int table[15][15];

int mat(int i, int j) {
	if (i == j)
		return 0;
	if (table[i][j] != -1)
		return table[i][j];
	int ans = 1000000000;
	for (int k = i; k <= j - 1; k++) {
		ans = min(ans, mat(i, k) + mat(k + 1, j) + p[i - 1] * p[k] * p[j]);
		//printf("%d\t%d\t%d\n%d\n\n", p[i-1], p[k], p[j], ans);
	}
	return table[i][j] = ans;
}

int main() {
	//ios::sync_with_stdio(false);

	int numMat;

	while (cin >> numMat && numMat) {
		memset(table, -1, sizeof table);
		p.resize(numMat * 2);

		for (int i = 0; i < p.size(); i++)
			cin >> p[i];

		int ans = mat(1, numMat);
		cout << ans << endl;
	}

	return 0;
}