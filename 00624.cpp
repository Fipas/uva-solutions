#include <bits/stdc++.h>

using namespace std;


bitset<20> used;
vector<int> tracks(20);
int maxValue = 0, N;

void backtrack(int pos, int numTracks, int sum, bitset<20> bused) {
	if (sum > N) return;
	if (pos == numTracks) {
		if (sum > maxValue) {
			maxValue = sum;
			used = bused;
		}
		return;
	}
	bused[pos] = 1;
	backtrack(pos + 1, numTracks, sum + tracks[pos], bused);
	bused[pos] = 0;
	backtrack(pos + 1, numTracks, sum, bused);
}

int main() {
	while (cin >> N) {
		int numTracks;
		maxValue = 0;
		used.reset();
		cin >> numTracks;
		for (int i = 0; i < numTracks; i++)
			cin >> tracks[i];
		backtrack(0, numTracks, 0, used);
		for (int i = 0; i < numTracks; i++)
			if (used[i])
				cout << tracks[i] << " ";
		cout << "sum:" << maxValue << endl;
	} 
	return 0;
}