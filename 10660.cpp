#include <bits/stdc++.h>

using namespace std;

struct Cell {
    int row;
    int column;
    int population;
};

int main() {

    int TC;
    cin >> TC;

    while (TC--) {
        int areas;
        vector<Cell> city;
        int minSum = 10000000;
        int u1, u2, u3, u4, u5;

        cin >> areas;
        city.resize(areas);

        for (int i = 0 ; i < areas; i++) {
            cin >> city[i].row >> city[i].column >> city[i].population;
        }

        for (int c1 = 0; c1 < 25; c1++) {
        for (int c2 = c1 + 1; c2 < 25; c2++) {
        for (int c3 = c2 + 1; c3 < 25; c3++) {
        for (int c4 = c3 + 1; c4 < 25; c4++) {
        for (int c5 = c4 + 1; c5 < 25; c5++) {
            int actSum = 0;
            for (int i = 0; i < city.size(); i++) {
                int minDist = 10000000;
                minDist = min(abs(city[i].row - c1 / 5) + abs(city[i].column - c1 % 5), minDist);
                minDist = min(abs(city[i].row - c2 / 5) + abs(city[i].column - c2 % 5), minDist);
                minDist = min(abs(city[i].row - c3 / 5) + abs(city[i].column - c3 % 5), minDist);
                minDist = min(abs(city[i].row - c4 / 5) + abs(city[i].column - c4 % 5), minDist);
                minDist = min(abs(city[i].row - c5 / 5) + abs(city[i].column - c5 % 5), minDist);
                actSum += minDist * city[i].population;
            }

            if (actSum < minSum) {
                u1 = c1;
                u2 = c2;
                u3 = c3;
                u4 = c4;
                u5 = c5;
                minSum = actSum;
            }
        }}}}}

        cout << u1 << " " << u2 << " " << u3 << " " << u4 << " " << u5 << endl;
    }

    return 0;
}