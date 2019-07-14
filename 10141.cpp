#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000000

int main() {
	iostream::sync_with_stdio(false);
	
	int req, prop;
	int c = 1;
	
	while (scanf("%d %d", &req, &prop)) {
		if (req == 0 && prop == 0) break;
		if (c > 1) cout << endl;
		
		string s;
		
		for (int i = 0; i < req; i++) getline(cin, s);
		
		float b_req = 0.0;
		float b_price = 1e37;
		string b_nome;
		
		float t_req;
		float t_price;
		
		
		for (int i = 0; i < prop; i++) {
			getline(cin, s);
			scanf("%f %f", &t_price, &t_req);
			if ((float) (t_req / req)  > (float) (b_req / req)) {
				b_req = t_req;
				b_price = t_price;
				b_nome = s;
			} else if ((float) (t_req / req)  == (float) (b_req / req)) {
				if (t_price < b_proc) {
					b_price = t_price;
					b_nome = s;
				}
			}
			
			for (int j = 0; j < t_req; j++) getline(cin, s);
			
		}
		
		cout << "RFP #" << c << endl;
		cout << b_nome << endl;
		c++;
		
	}
	return 0;
}
