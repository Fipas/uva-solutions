#include <bits/stdc++.h>

using namespace std;

vector<int> numbers;
bitset<12> used;
map<string, bool> visited;
bool found = false;

void backtrack(int sum, int maxSum, bitset<12> used, int next, int maxNext) {
    if (sum == maxSum) {
        found = true;
        bool plus = false;
        stringstream sol;
        for (int i = 0; i < next; i++) {
            if (used[i]) {
                if (plus) 
                    sol << "+" << numbers[i];
                else
                    sol << numbers[i];
                plus = true;
            } 
        }

        if (!visited[sol.str()]) {
            cout << sol.str() << endl;
            visited[sol.str()] = true;
        }

        return;
    }

    if (next == maxNext)
        return;

    if (sum + numbers[next] <= maxSum) {
        used[next] = 1;
        backtrack(sum + numbers[next], maxSum, used, next + 1, maxNext);
    }

    used[next] = 0;
    backtrack(sum, maxSum, used, next + 1, maxNext);
}

int main() {

    int t, n;

    while (cin >> t >> n && n != 0) {
        used.reset();
        numbers.resize(n);
        visited.clear();
        found = false;
        
        cout << "Sums of " << t << ":\n";
        for (int i = 0; i < n; i++)
            cin >> numbers[i];
        backtrack(0, t, used, 0, n);
        if (!found)
            cout << "NONE\n";
    }

    return 0;
}