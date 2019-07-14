#include <bits/stdc++.h>

using namespace std;

vector<int> seq;
vector<int> lis;
vector<int> pred;
vector<int> lisId;

void printLis(int i) {
	if (pred[i] == -1) {
		cout << seq[i] << endl;
	} else {
		printLis(pred[i]);
		cout << seq[i] << endl;
	}

}

int main() {
	ios::sync_with_stdio(false);

	int n, lisMax = 0, start = 0;
	vector<int>::iterator it;

	while (cin >> n) {
		seq.push_back(n);
		it = lower_bound(lis.begin(), lis.end(), n);

		if (it == lis.end()) {
			lisId.push_back(seq.size() - 1);
			if (it - lis.begin())
				pred.push_back(lisId[it - lis.begin() - 1]);
			else
				pred.push_back(-1);
			lis.push_back(n);
			lisMax++;
			start = seq.size() - 1;
		} else {
			lisId[it - lis.begin()] = seq.size() - 1;
			*it = n;

			if (it - lis.begin())
				pred.push_back(lisId[it - lis.begin() - 1]);
			else
				pred.push_back(-1);

			if (it - lis.begin() == lisMax)
				start = seq.size() - 1;
		}

		//cout << lis.size() << endl;
		//cout << pred.size() << endl;
		//cout << lisId.size() << endl << endl;
	}

	cout << lisMax << "\n-\n";
	printLis(start);

	return 0;
}