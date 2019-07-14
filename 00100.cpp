#include <bits/stdc++.h>

using namespace std;

long long computeCycle(long long n) {
	long long length = 1;

	while (n != 1 && length++)
		n = n % 2 == 0 ? n / 2 : n * 3 + 1;

	return length;
}

int main() {
	ios::sync_with_stdio(false);

	long long i, j;

	while (cin >> i >> j) {
		long long maxCycle = -1;

		cout << i << " " << j << " ";

		if (i > j)
			swap(i, j);

		for (long long c = i; c <= j; c++)
			maxCycle = max(maxCycle, computeCycle(c));

		cout << maxCycle << "\n";
	}

	return 0;
}