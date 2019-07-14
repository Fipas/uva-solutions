#include <bits/stdc++.h>

using namespace std;

int main() {
	int numHeads, numKnights;

	while (cin >> numHeads >> numKnights && (numHeads || numKnights)) {
		vector<int> heads(numHeads);
		vector<int> knights(numKnights);
		int slayed = 0, toPay = 0;

		for (int i = 0; i < numHeads; i++)
			cin >> heads[i];

		for (int i = 0; i < numKnights; i++)
			cin >> knights[i];

		sort(heads.begin(), heads.end());
		sort(knights.begin(), knights.end());

		int headIndex = 0;
		for (int i = 0; i < knights.size() && headIndex < heads.size(); i++) {
			if (knights[i] < heads[headIndex]) continue;
			toPay += knights[i];
			headIndex++;
			slayed++;
		}

		if (slayed == numHeads)
			cout << toPay << endl;
		else
			cout << "Loowater is doomed!\n";
	}

	return 0;
}