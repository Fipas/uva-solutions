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
#include <cstdlib>
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

struct user
{
	int id;
	int solved;
	int penalty;
	bool isSolved[10];
	int attempt[10];
	int visited;
};

bool comp(user a, user b) {
	if (a.visited == b.visited) {
		if (a.solved == b.solved) {
			if (a.penalty == b.penalty)
				return a.id < b.id;
			return a.penalty < b.penalty;
		}

		return a.solved > b.solved;
	}

	return a.visited > b.visited;
}

int main() {
	ios::sync_with_stdio(false);

	int t;
	cin >> t;

	while (t--) {
		string s1, s2, w;
		map<char, pii> state;
		int culprit = 0;

		for (int i = 'A'; i <= 'L'; i++) {
			state[i].first = 0;
			state[i].second = 0;
		}

		for (int i = 0; i < 3; i++) {
			cin >> s1 >> s2 >> w;

			if (w == "even") {
				for (int i = 0; i < s1.size(); i++) {
					state[s1[i]].first--;
					state[s1[i]].second--;
					culprit = max(culprit, max(state[s1[i]].first, state[s1[i]].second));
				}

				for (int i = 0; i < s2.size(); i++){
					state[s2[i]].first--;
					state[s2[i]].second--;
					culprit = max(culprit, max(state[s2[i]].first, state[s2[i]].second));
				}
			} else if (w == "up") {
				for (int i = 0; i < s1.size(); i++) {
					state[s1[i]].first++;
					culprit = max(culprit, state[s1[i]].first);
				}
						

				for (int i = 0; i < s2.size(); i++) {
					state[s2[i]].second++;
					culprit = max(culprit, state[s2[i]].second);
				}
			} else {
				for (int i = 0; i < s1.size(); i++) {
					state[s1[i]].second++;
					culprit = max(culprit, state[s1[i]].second);
				}
					

				for (int i = 0; i < s2.size(); i++) {
					state[s2[i]].first++;
					culprit = max(culprit, state[s2[i]].first);
				}
			}
		}

		map<char, pii>::iterator it;

		for (it = state.begin(); it != state.end(); ++it) {
			if ((it->second).first == culprit || (it->second).second == culprit) {
				cout << it->first << " is the counterfeit coin and it is " 
					 << ((it->second).first >= (it->second).second ? "heavy" : "light") << ".\n";
				break;
			}
		}
	}

	return 0;
}