#include <bits/stdc++.h>

using namespace std;

int main() {

    int queries;
    string line;
    vector<vector<int> > letters(200);

    cin >> line >> queries;

    for (int i = 0; i < line.size(); i++) {
        letters[line[i]].push_back(i);
    }

    while (queries--) {
        bool matched = true;
        int start = -1, end, nextAvail = 0;
        string query;

        cin >> query;

        for (int i = 0; i < query.size(); i++) {
            vector<int>::iterator it = lower_bound(letters[query[i]].begin(), 
                                                   letters[query[i]].end(), nextAvail);

            //cout << "letter: " << (char) (index + 'a') << "   pos: " << *it << endl;

            if (it == letters[query[i]].end()) {
                matched = false;
                break;
            }

            nextAvail = *it + 1;

            if (start == -1)
                start = *it;
            end = *it;
        }

        if (matched) {
            cout << "Matched " << start << " " << end << endl;
        } else {
            cout << "Not matched\n";
        }
    }


    return 0;
}