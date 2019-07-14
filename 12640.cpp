#include <bits/stdc++.h>

using namespace std;

int main() {
	string line;

	while (getline(cin, line)) {
		stringstream stream;
		stream << line;

		int n;
		vector<int> v;

		while (stream >> n) {
			v.push_back(n);
		}

		int maxL = 0;
		int maxG = 0;

		for (int i = 0; i < v.size(); i++) {
			maxL += v[i];
			if (maxL < 0) maxL = 0;
			maxG = max(maxG, maxL);
		}

		cout << maxG << endl;
	}

	return 0;
}