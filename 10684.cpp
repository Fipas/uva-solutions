#include <bits/stdc++.h>

using namespace std;

int main() {
	//ios::sync_with_stdio(false);

	int n;

	while (cin >> n && n) {
		vector<int> bets(n);
		bool allNeg = true;

		for (int i = 0; i < n; i++) {
			cin >> bets[i];
			if (bets[i] > 0)
				allNeg = false;
		}

		if (allNeg) {
			cout << "Losing streak.\n";
		} else {
			int ans = 0;
			int sum = 0;

			for (int i = 0; i < n; i++) {
				sum += bets[i];
				if (sum < 0)
					sum = 0;
				ans = max(sum, ans);
			}

			cout << "The maximum winning streak is " << ans << ".\n";
		}

	}

	return 0;
}