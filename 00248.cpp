#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <cmath>
#include <sstream>
using namespace std;

typedef long long               ll;
typedef long double             ld;
typedef vector<int>             vi;
typedef vector<vi>              vvi;
typedef pair<int, int>          pii;
typedef vector<pii>             vii; // vector of integer pairs
typedef set<int>                si;
typedef map<string, int>        msi;

#define VAR(a,b)        __typeof(b) a=(b)
#define REP(i,n)        for(int i=0;i<(n);++i)     // 0 to n
#define FOR(i,a,b)      for(VAR(i,a);i<=(b);++i)  // a to b, a < b
#define FORD(i,a,b)     for(VAR(i,a);i>=(b);--i)  // a to b, a > b
#define FORE(a,b)       for(VAR(a,(b).begin());a!=(b).end();++a) // for each, e.g. FORE(iter, vect) cout << *iter << endl;
#define SIZE(a)         ((int)((a).size())) // e.g. for (int i = 0; i < SIZE(vect); ++i)
#define ALL(x)          (x).begin(),(x).end() // e.g. sort(ALL(vect))
#define FILL(x,a)       memset(x,a,sizeof(x))
#define CLR(x)          memset(x,0,sizeof(x))
#define VE              vector<int>
#define SZ              size()
#define PB              push_back
#define MP              make_pair
#define FI              first
#define SE              second
#define TRsi(c,it)      for(si::iterator it=(c).begin();it!=(c).end();it++) // cout << " " << *it;
#define TRvii(c,it)     for(vii::iterator it=(c).begin();it!=(c).end();it++) // cout << " " << *it;
#define TRmsi(c,it)     for(msi::iterator it=(c).begin();it!=(c).end();it++)
#define INF             2000000000 // 2 billion
#define SQ(x)           ((x)*(x))
#define getLastDigit(i) (i%10)
#define remLastDigit(i) (i/10)

const double PI=acos(-1.0); //NOTES: PI
const double EPS=1e-11; //NOTES: EPS

// Translator
bool isUpper(char c){return c>='A' && c<='Z';} //NOTES: isUpper(
bool isLower(char c){return c>='a' && c<='z';} //NOTES: isLower(
bool isLetter(char c){return (c>='A' && c<='Z') || (c>='a' && c<='z');} //NOTES: isLetter(
bool isDigit(char c){return c>='0' && c<='9';} //NOTES: isDigit(
char toLower(char c){return (isUpper(c))?(c+32):c;} //NOTES: toLower(
char toUpper(char c){return (isLower(c))?(c-32):c;} //NOTES: toUpper(
int str2int(string s){int r=0;istringstream sin(s);sin>>r;return r;} //NOTES: str2int(
int char2int(char c){return (int)c;} //NOTES: char2int(

// Numeric functions
bool isPowOf2(int i){return (i & i-1) == 0;} //NOTES: isPowOf2


int main() {
	ios::sync_with_stdio(false);

	int prince[2], princess[3];

	cin >> princess[0] >> princess[1] >> princess[2] >> prince[0] >> prince[1];

	while (princess[0] || princess[1] || princess[2] || prince[0] || prince[1]) {
		bool found = false;

		for (int i = 1; i <= 52; i++) {
			if (i != princess[0] && i != princess[1] && i != princess[2] &&
				i != prince[0] && i != prince[1]) {
				bool all_win = true;
				int n_p[3], n_pss[3];

				n_p[0] = prince[0];
				n_p[1] = prince[1];
				n_p[2] = i;

				n_pss[0] = princess[0];
				n_pss[1] = princess[1];
				n_pss[2] = princess[2];

				sort(n_p, n_p + 3);
				sort(n_pss, n_pss + 3);

				do {
					do {
						int losses = 0;
						for (int i = 0; i < 3; i++) {
							if (n_p[i] < n_pss[i])
								losses++;
						}

						if (losses >= 2) all_win = false;

					} while (next_permutation(n_p, n_p + 3));
				} while (next_permutation(n_pss, n_pss + 3));

				if (all_win) {
					cout << i << endl;
					found = true;
					break;
				}
			}
		}

		if (!found)
			cout << "-1\n";

		cin >> princess[0] >> princess[1] >> princess[2] >> prince[0] >> prince[1];
	}

	return 0;
}