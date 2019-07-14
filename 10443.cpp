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

int wx[] = {1, -1, 0, 0};
int wy[] = {0, 0, 1, -1};

int main() {
	ios::sync_with_stdio(false);

	int t;

	cin >> t;

	for (int i = 0; i < t; i++) {
		if (i != 0)
			cout << endl;

		int r, c, n;
		cin >> r >> c >> n;

		char board[r + 2][c + 2];
		char new_board[r + 2][c + 2];


		for (int j = 1; j <= r; j++) {
			for (int k = 1; k <= c; k++) {
				cin >> board[j][k];
			}
		}

		for (int l = 0; l < n; l++) {
			FILL(new_board, '-');
			for (int j = 1; j <= r; j++) {
				for (int k = 1; k <= c; k++) {
					if (board[j][k] == 'R') {
						for (int o = 0; o < 4; o++) {
							int nj = j + wx[o];
							int nk = k + wy[o];

							if (board[nj][nk] == 'P')
								new_board[j][k] = 'P';
						}
					}

					if (board[j][k] == 'P') {
						for (int o = 0; o < 4; o++) {
							int nj = j + wx[o];
							int nk = k + wy[o];

							if (board[nj][nk] == 'S')
								new_board[j][k] = 'S';
						}
					}

					if (board[j][k] == 'S') {
						for (int o = 0; o < 4; o++) {
							int nj = j + wx[o];
							int nk = k + wy[o];

							if (board[nj][nk] == 'R')
								new_board[j][k] = 'R';
						}
					}
				}
			}



			for (int j = 1; j <= r; j++) {
				for (int k = 1; k <= c; k++) {
					board[j][k] = new_board[j][k] != '-' ? new_board[j][k] : board[j][k];
				}
			}
		}

		for (int j = 1; j <= r; j++) {
			for (int k = 1; k <= c; k++) {
				cout << board[j][k];
			}
			cout << endl;
		}


	}

	return 0;
}