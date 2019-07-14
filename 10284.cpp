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

bool isValid(int ar, int ac, int mr, int mc) {
	return ar < mr && ar >= 0 && ac < mc && ac >= 0;
}

bool isPiece(char ch) {
	ch = toLower(ch);
	return ch == 'p' || ch == 'n' || ch == 'b' || ch == 'r' || ch == 'q' || ch == 'k';
}

int kr[8] = {2, 2, 1, 1, -1, -1, -2, -2};
int kc[8] = {1, -1, 2, -2, 2, -2, 1, -1};

int kinr[8] = {1, 1, 1, 0, 0, -1, -1, -1};
int kinc[8] = {-1, 0, 1, -1, 1, -1, 0, 1};


int main() {
	ios::sync_with_stdio(false);

	string s;

	while (cin >> s) {
		char board[8][8];
		bool board_nat[8][8];
		FILL(board, ' ');
		FILL(board_nat, false);

		int r = 0, c = 0;

		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '/') {
				r = 0;
				c++;
				continue;
			}

			if (isDigit(s[i])) {
				r += (s[i] - '0');
				continue;
			}

			if (isPiece(s[i])) {
				board[c][r] = s[i];
				r++;
				continue;
			}
		}

		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {

				if (board[i][j] == 'p') {
					board_nat[i][j] = true;

					int ni = i + 1;
					int nj = j + 1;

					if (isValid(ni, nj, 8, 8)) {
						board_nat[ni][nj] = true;
					}

					nj = j - 1;

					if (isValid(ni, nj, 8, 8)) {
						board_nat[ni][nj] = true;
					}
				}

				if (board[i][j] == 'P') {
					board_nat[i][j] = true;

					int ni = i - 1;
					int nj = j + 1;

					if (isValid(ni, nj, 8, 8)) {
						board_nat[ni][nj] = true;
					}

					nj = j - 1;

					if (isValid(ni, nj, 8, 8)) {
						board_nat[ni][nj] = true;
					}
				}

				if (board[i][j] == 'N' || board[i][j] == 'n') {
					board_nat[i][j] = true;

					for (int k = 0; k < 8; k++) {
						int ni = i + kr[k];
						int nj = j + kc[k];

						if (isValid(ni, nj, 8, 8)) {
							board_nat[ni][nj] = true;
						} 
					}
				}

				if (board[i][j] == 'K' || board[i][j] == 'k') {
					board_nat[i][j] = true;

					for (int k = 0; k < 8; k++) {
						int ni = i + kinr[k];
						int nj = j + kinc[k];

						if (isValid(ni, nj, 8, 8)) {
							board_nat[ni][nj] = true;
						} 
					}
				}

				if (board[i][j] == 'B' || board[i][j] == 'b') {
					board_nat[i][j] = true;

					int ni = i - 1;
					int nj = j - 1;


					while (isValid(ni, nj, 8, 8) && !isPiece(board[ni][nj])) {
						board_nat[ni][nj] = true;
						ni--;
						nj--;
					}

					ni = i + 1;
					nj = j + 1;

					while (isValid(ni, nj, 8, 8) && !isPiece(board[ni][nj])) {
						board_nat[ni][nj] = true;
						ni++;
						nj++;
					}

					ni = i - 1;
					nj = j + 1;

					while (isValid(ni, nj, 8, 8) && !isPiece(board[ni][nj])) {
						board_nat[ni][nj] = true;
						ni--;
						nj++;
					}

					ni = i + 1;
					nj = j - 1;

					while (isValid(ni, nj, 8, 8) && !isPiece(board[ni][nj])) {
						board_nat[ni][nj] = true;
						ni++;
						nj--;
					}
				}

				if (board[i][j] == 'R' || board[i][j] == 'r') {
					board_nat[i][j] = true;

					int ni = i + 1;
					int nj = j;


					while (isValid(ni, nj, 8, 8) && !isPiece(board[ni][nj])) {
						board_nat[ni][nj] = true;
						ni++;
					}

					ni = i - 1;
					nj = j;

					while (isValid(ni, nj, 8, 8) && !isPiece(board[ni][nj])) {
						board_nat[ni][nj] = true;
						ni--;
					}

					ni = i;
					nj = j + 1;

					while (isValid(ni, nj, 8, 8) && !isPiece(board[ni][nj])) {
						board_nat[ni][nj] = true;
						nj++;
					}

					ni = i;
					nj = j - 1;

					while (isValid(ni, nj, 8, 8) && !isPiece(board[ni][nj])) {
						board_nat[ni][nj] = true;
						nj--;
					}
				}

				if (board[i][j] == 'Q' || board[i][j] == 'q') {
					board_nat[i][j] = true;

					int ni = i - 1;
					int nj = j - 1;


					while (isValid(ni, nj, 8, 8) && !isPiece(board[ni][nj])) {
						board_nat[ni][nj] = true;
						ni--;
						nj--;
					}

					ni = i + 1;
					nj = j + 1;

					while (isValid(ni, nj, 8, 8) && !isPiece(board[ni][nj])) {
						board_nat[ni][nj] = true;
						ni++;
						nj++;
					}

					ni = i - 1;
					nj = j + 1;

					while (isValid(ni, nj, 8, 8) && !isPiece(board[ni][nj])) {
						board_nat[ni][nj] = true;
						ni--;
						nj++;
					}

					ni = i + 1;
					nj = j - 1;

					while (isValid(ni, nj, 8, 8) && !isPiece(board[ni][nj])) {
						board_nat[ni][nj] = true;
						ni++;
						nj--;
					}

					ni = i + 1;
					nj = j;


					while (isValid(ni, nj, 8, 8) && !isPiece(board[ni][nj])) {
						board_nat[ni][nj] = true;
						ni++;
					}

					ni = i - 1;
					nj = j;

					while (isValid(ni, nj, 8, 8) && !isPiece(board[ni][nj])) {
						board_nat[ni][nj] = true;
						ni--;
					}

					ni = i;
					nj = j + 1;

					while (isValid(ni, nj, 8, 8) && !isPiece(board[ni][nj])) {
						board_nat[ni][nj] = true;
						nj++;
					}

					ni = i;
					nj = j - 1;

					while (isValid(ni, nj, 8, 8) && !isPiece(board[ni][nj])) {
						board_nat[ni][nj] = true;
						nj--;
					}
				}



			}
		}

		int count = 0;

		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (board_nat[i][j] == false)
					count++;
				//cout << board_nat[i][j];
			}
			//cout << endl;
		}

		cout << count << "\n";
	}

	return 0;
}