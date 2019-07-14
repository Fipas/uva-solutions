#include <bits/stdc++.h>

using namespace std;

vector<int> seq;
vector<int> lis;
vector<int> pred;
vector<int> lisId;

int memo[210];
vector<int> num;
int n, q, d, m;



int knap(int quantity, int index, int sum) {
	//printf("%d\t%d\t%d\n", quantity, index, sum);

	if (quantity == m) {
		if (sum % d == 0)
			return 1;
		return 0;
	}

	if (index == n)
		return 0;

	if (memo[index] != -1)
		return memo[index];

	int ans = 0;
	ans = knap(quantity + 1, index + 1, sum + num[index]) +
		  knap(quantity, index + 1, sum);

	return memo[index] = ans;
}

int main() {
	ios::sync_with_stdio(false);

	int setNum = 1;
	while (cin >> n >> q && (n || q)) {
		cout << "SET " << setNum << ":\n";
		num.resize(n);
		for (int i = 0; i < n; i++)
			cin >> num[i];

		for (int i = 0; i < q; i++) {
			cin >> d >> m;
			memset(memo, -1, sizeof memo);
			int ans = knap(0, 0, 0);
			cout << "QUERY " << i + 1 << ": " << ans << endl;
		}
	}

	return 0;
}