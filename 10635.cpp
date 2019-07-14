#include <bits/stdc++.h>

using namespace std;

int main() {
	int test;

	cin >> test;

	for (int t = 1; t <= test; t++) {
		int n, p1, p2;
		cin >> n >> p1 >> p2;
		vector<int> v1(p1);
		vector<int> v2(p2);
		vector<int> dict(n * n, 0);	
		vector<int> lis;
		int lisSize = 0;

		for (int i = 0; i < p1 + 1; i++)
			cin >> v1[i];

		for (int i = 0; i < p2 + 1	; i++) {
			cin >> v2[i];
			dict[v2[i]] = i + 1;
			//cout << "v2[i]: " << v2[i] << "\t" << "dict: " << dict[v2[i]] << endl; 
		}

		vector<int>::iterator it;

		for (int i = 0; i < p1 + 1; i++) {
			if (dict[v1[i]] == 0) continue;
			it = lower_bound(lis.begin(), lis.end(), dict[v1[i]]);
			if (it == lis.end()) {
				lis.push_back(dict[v1[i]]);
				lisSize++;
			} else {
				*it = dict[v1[i]];
			}

			//cout << "v1[i]: " << v1[i] << "\t" << "dict: " << dict[v1[i]] << endl; 

			//cout << "lis: "; 
			/*for (int j = 0; j < lis.size(); j++) {
				cout << lis[j] << " ";
			}
			cout << endl;*/
		}

		cout << "Case " << t << ": " << lisSize << endl;
	}

	return 0;
}