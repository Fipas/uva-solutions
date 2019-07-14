#include <bits/stdc++.h>

using namespace std;


bitset<33> isPrime;
int n;
bitset<17> used;

void backtrack(int circleSize, vector<int> circle, bitset<17> used, int next) {
	circle.push_back(next);
	used[next] = 1;

	if (circleSize == n) {
		if (isPrime[circle[0] + circle[n - 1]]) {
			cout << circle[0];
			for (int i = 1; i < n; i++)
				cout << " " << circle[i];
			cout << endl;
		}
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (!used[i] && isPrime[circle[circleSize - 1] + i]) {
			backtrack(circleSize + 1, circle, used, i);
		}
	}
}

int main() {
	isPrime[1] = 1;
	isPrime[2] = 1;
	isPrime[3] = 1;
	isPrime[5] = 1;
	isPrime[7] = 1;
	isPrime[11] = 1;
	isPrime[13] = 1;
	isPrime[17] = 1;
	isPrime[19] = 1;
	isPrime[23] = 1;
	isPrime[29] = 1;
	isPrime[31] = 1;

	int numCase = 1;
	while (cin >> n) {
		if (numCase > 1)
			cout << endl;
		cout << "Case " << numCase++ << ":\n";
		used.reset();
		used[1] = 1;
		vector<int> circle;
		backtrack(1, circle, used, 1);
	}
	return 0;
}