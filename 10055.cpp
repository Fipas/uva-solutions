#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);

	unsigned int i, j;

	while (cin >> i >> j) {
		if (i > j)
			swap(i, j);
		cout << j - i << endl;
	}

	return 0;
}