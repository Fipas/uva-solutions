#include <bits/stdc++.h>

using namespace std;

struct el {
	int index;
	int w;
	int s;
};

vector<int> pred;
vector<int> best;
vector<el> els;

bool comp(el a, el b) {
	if (a.w == b.w) {
		return a.s > b.s;
	}
	return a.w < b.w;
}

void printLDS(int i) {
	if (pred[i] == -1) {
		cout << els[i].index << endl;
	} else {
		printLDS(pred[i]);
		cout << els[i].index << endl;
	}
}

int main() {
	//ios::sync_with_stdio(false);

	int w, s, index = 1;

	while (cin >> w >> s) {
		el e;
		e.w = w;
		e.s = s;
		e.index = index;
		els.push_back(e);
		index++;
	}

	pred.assign(els.size(), -1);
	best.assign(els.size(), 1);
	int maxLis = 1, lastIndex = 0;

	sort(els.begin(), els.end(), comp);

	/*for (int i = 0; i < els.size(); i++) {
		cout << els[i].w << "		" << els[i].s << endl;
	}*/

	for (int i = 0; i < els.size(); i++) {
		//cout << els[i].w << "		" << els[i].s << endl;
		for (int j = i - 1; j >= 0; j--) {
			if (els[j].s > els[i].s && els[j].w != els[i].w) {
				//cout << "YES - " << els[i].s << " < " << els[j].s << endl;
				//cout << "BEST UNTIL NOW - " << best[i] << endl;
				if (best[i] < best[j] + 1) {
					best[i] = best[j] + 1;
					pred[i] = j;
				}
				//cout << "BEST AFTER - " << best[i] << endl << endl;
			}
		}
	}

	for (int i = 0; i < best.size(); i++) {
		if (best[i] > maxLis) {
			maxLis = best[i];
			lastIndex = i;
		}
	}

	cout << maxLis << endl;
	printLDS(lastIndex);

	return 0;
}