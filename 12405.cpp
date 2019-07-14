#include <bits/stdc++.h>

using namespace std;

bool comp(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first)
        return a.second > b.second;
    return a.first < b.first;
}

int main() {

    int TC;
    cin >> TC;

    for (int test = 1; test <= TC; test++) {
        cout << "Case " << test << ": ";

        int fieldSize;
        vector<char> field;
        int scarecrows = 0;
        vector<pair<int, int> > intervals;

        cin >> fieldSize;
        field.resize(fieldSize);

        for (int i = 0; i < fieldSize; i++)
            cin >> field[i];

        for (int i = 0; i < fieldSize; i++) {
            if (field[i] == '.')
                intervals.push_back(make_pair(i, min(i + 2, fieldSize - 1)));
        }

        sort(intervals.begin(), intervals.end(), comp);

        int next = 0;
        for (int i = 0; i < intervals.size(); i++) {
            if (intervals[i].first < next) continue;
            next = intervals[i].second + 1;
            scarecrows++;
        }

        cout << scarecrows << endl;
    }

    return 0;
}