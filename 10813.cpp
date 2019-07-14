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
#include <utility>
#include <cctype>
#include <cstring>
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

	int t;
	cin >> t;

	while (t--) {
		int b[5][5];
		int bf[5][5];

		memset(bf, 0, sizeof(bf));
		bf[2][2] = 1;
		b[2][2] = -1;

		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if (i == 2 && j == 2) continue;
				cin >> b[i][j];
			}
		}

		int n = 0;
		bool bingo = false;

		for (int k = 0; k < 75; k++) {
			int v;
			cin >> v;

			if (!bingo) {
				//cout << "Sorteados: " << k << endl;
				for (int i = 0; i < 5; i++) {
					for (int j = 0; j < 5; j++) {
						if (b[i][j] == v)
							bf[i][j] = 1;
						//cout << bf[i][j] << "  ";
					}
					//cout << endl;
				}

				//cout << endl << endl;

				int r1 = 0, r2 = 0, r3 = 0, r4 = 0, r5 = 0, 
					c1 = 0, c2 = 0, c3 = 0, c4 = 0, c5 = 0, d1 = 0, d2 = 0;

				for (int i = 0; i < 5; i++) {
					r1 += bf[0][i];
					r2 += bf[1][i];
					r3 += bf[2][i];
					r4 += bf[3][i];
					r5 += bf[4][i];
					c1 += bf[i][0];
					c2 += bf[i][1];
					c3 += bf[i][2];
					c4 += bf[i][3];
					c5 += bf[i][4];
					d1 += bf[i][i];
					d2 += bf[i][5 - i - 1];
				}

				if (r1 == 5 || r2 == 5 || r3 == 5 || r4 == 5 || r5 == 5 ||
					c1 == 5 || c2 == 5 || c3 == 5 || c4 == 5 || c5 == 5 ||
					d1 == 5 || d2 == 5) {
					bingo = true;
					n = k + 1;
				}
			}
		}

		cout << "BINGO after " << n << " numbers announced\n";
	}

	return 0;
}