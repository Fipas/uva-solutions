#include <bits/stdc++.h>

using namespace std;

int main() {

    int TC;
    cin >> TC;

    for (int c = 0; c < TC; c++) {
        if (c) cout << endl;

        int numCandidates, numVotes = 0;
        string line;
        bool winnerFound = false;
        int maxVotes = -1, minVotes = 1000;
        vector<string> candidates;
        vector< vector<int> > votes(1010);

        cin >> numCandidates;

        bool eliminated[numCandidates + 1];
        int votesCandidate[numCandidates + 1];
        memset(eliminated, false, sizeof eliminated);
        memset(votesCandidate, 0, sizeof votesCandidate);

        cin.ignore();

        for (int i = 0; i < numCandidates; i++) {
            getline(cin, line);
            candidates.push_back(line);
        }

        while(getline(cin, line) && !line.empty()) {
            istringstream tokenizer(line);
            for (int i = 0; i < numCandidates; i++) {
                int val;
                tokenizer >> val;
                votes[numVotes].push_back(val);
            }
            numVotes++;
        }

        while (!winnerFound) {
            maxVotes = -1;
            minVotes = 1010;

            for (int i = 1; i <= numCandidates; i++)
                votesCandidate[i] = 0;

            for (int i = 0; i < numVotes; i++) {
                for (int j = 0; j < numCandidates; j++) {
                    if (eliminated[votes[i][j]]) continue;
                    else {
                        votesCandidate[votes[i][j]]++;
                        break;
                    }
                }
            }

            for (int i = 1; i <= numCandidates; i++) {
                if (!eliminated[i]) {
                    maxVotes = max(maxVotes, votesCandidate[i]);
                    minVotes = min(minVotes, votesCandidate[i]);
                }
            }

            if (maxVotes > numVotes / 2 || maxVotes == minVotes) {
                winnerFound = true;
            }

            if (maxVotes != minVotes) {
                for (int i = 1; i <= numCandidates; i++) {
                    if (votesCandidate[i] == minVotes) {
                        eliminated[i] = true;
                    }
                }
            }
        }

        for (int i = 1; i <= numCandidates; i++)
            if (!eliminated[i])
                cout << candidates[i - 1] << endl;
    }

    return 0;
}