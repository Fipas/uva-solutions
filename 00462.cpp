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

	string s;
	char suits[5] = {'S', 'H', 'D', 'C'};

	while (cin >> s) {
		vector<string> cards;
		int points = 0;
		int points567 = 0;
		map<char, int> cardsBySuit;
		map<char, bool> isStopped;

		cardsBySuit[s[1]]++;
		cards.PB(s);

		for (int i = 0; i < 12; i++) {
			cin >> s;
			cardsBySuit[s[1]]++;
			cards.PB(s);
		}


		for (int i = 0; i < cards.size(); i++) {
			if (cards[i][0] == 'A') {
				points += 4;
				isStopped[cards[i][1]] = true;
			}

			if (cards[i][0] == 'K') {
				points += 3;
				if (cardsBySuit[cards[i][1]] == 1)
					points--;
				if (cardsBySuit[cards[i][1]] >= 2)
					isStopped[cards[i][1]] = true;
			}

			if (cards[i][0] == 'Q') {
				points += 2;
				if (cardsBySuit[cards[i][1]] <= 2)
					points--;
				if (cardsBySuit[cards[i][1]] >= 3)
					isStopped[cards[i][1]] = true;
			}

			if (cards[i][0] == 'J') {
				points += 1;
				if (cardsBySuit[cards[i][1]] <= 3)
					points--;
			}

		}

		for (int i = 0; i < 4; i++) {
			if (cardsBySuit[suits[i]] == 2)
				points567++;
			else if (cardsBySuit[suits[i]] == 1)
				points567 += 2;
			else if (cardsBySuit[suits[i]] == 0)
				points567 += 2;
		}

		if (points >= 16 && isStopped['S'] && isStopped['H'] && isStopped['D'] && isStopped['C']) {
				cout << "BID NO-TRUMP\n";
		} else if (points + points567 < 14) {
			cout << "PASS\n";
		} else {
			int maxSuits = -1;
			for (int i = 0; i < 4; i++) {
				maxSuits = max(maxSuits, cardsBySuit[suits[i]]);
			}

			for (int i = 0; i < 4; i++) {
				if (cardsBySuit[suits[i]] == maxSuits) {
					cout << "BID " << suits[i] << "\n";
					break;
				}
			}
		}
		
	}

	

	return 0;
}