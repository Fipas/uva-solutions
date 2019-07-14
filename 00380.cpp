#include <bits/stdc++.h>

using namespace std;

struct order {
	int start;
	int end;
	int forward;
};

bool comp(order a, order b) {
	return a.start < b.start;
}

int main() {
	//ios::sync_with_stdio(false);

	int t;
	cin >> t;
	cout << "CALL FORWARDING OUTPUT\n";

	for (int c = 1; c <= t; c++) {
		cout << "SYSTEM " << c << endl;
		int call, forward, start, end;
		map<int, vector<order> > v;

		while (cin >> call && call != 0000) {
			cin >> start >> end >> forward;
			order o;
			o.start = start;
			o.end = start + end;
			o.forward = forward;
			v[call].push_back(o);
		}

		map<int, vector<order> >::iterator it;

		for (it = v.begin(); it != v.end(); ++it)
			sort(it->second.begin(), it->second.end(), comp);

		while (cin >> start && start != 9000) {
			cin >> call;
			int resp = 0;
			int aux_call = call;

			for (int i = 0; i < v[call].size(); i++) {
				if (start >= v[call][i].start && start <= v[call][i].end)
					resp = v[call][i].forward;
			}

			if (resp == 0) {
				resp = call;
			} else if (resp == call) {
				resp = 9999;
			}

			while (resp != aux_call && resp != 9999) {
				if (resp == call) {
					resp = 9999;
					break;
				}

				aux_call = resp;

				for (int i = 0; i < v[aux_call].size(); i++) {
					if (start >= v[aux_call][i].start && start <= v[aux_call][i].end)
						resp = v[aux_call][i].forward;
				}
			}

			printf("AT %04d CALL TO %04d RINGS %04d\n", start, call, resp);
		}
	}

	cout << "END OF OUTPUT\n";

	return 0;
}