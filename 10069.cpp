#include <bits/stdc++.h>

using namespace std;

string s, sub;
int table[10100][110];

int ways(int i, int j) {

}

int main() {
	//ios::sync_with_stdio(false);

	int TC;
	cin >> TC;

	while (TC--) {
		memset(table, -1, sizeof table);
		cin >> s >> sub;

		int ans = ways(0, 0);
		cout << ans << endl;
	}

	return 0;
}