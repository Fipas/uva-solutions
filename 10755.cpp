#include <bits/stdc++.h>

using namespace std;

int main() {
	//ios::sync_with_stdio(false);

	int TC;
	cin >> TC;

	while (TC--) {
		int A, B, C;

		cin >> A >> B >> C;

		long long m[A][B][C];

		for (int i = 0; i < A; i++) {
			for (int j = 0; j < B; j++) {
				for (int k = 0; k < C; k++) {
					cin >> m[i][j][k];
					if (k > 0)
						m[i][j][k] += m[i][j][k-1];
					if (j > 0)
						m[i][j][k] += m[i][j-1][k];
					if (k > 0 && j > 0)
						m[i][j][k] -= m[i][j-1][k-1];
				}
			}
		}

		long long ans = LLONG_MIN;

		//cout << ans << endl;

		for (int j = 0; j < B; j++) {
			for (int k = 0; k < C; k++) {
				for (int sj = j; sj < B; sj++) {
					for (int sk = k; sk < C; sk++) {
						long long sum = 0;
						for (int i = 0; i < A; i++) {
							long long subRect = m[i][sj][sk];
							if (j > 0)
								subRect -= m[i][j-1][sk];
							if (k > 0)
								subRect -= m[i][sj][k-1];
							if (j > 0 && k > 0)
								subRect += m[i][j-1][k-1];

							if (subRect >= 0 && sum <= 0)
								sum = subRect;
							else
								sum += subRect;

							ans = max(ans, sum);
						}
					}
				}
			}
		}

		cout << ans << endl;
	}

	return 0;
}