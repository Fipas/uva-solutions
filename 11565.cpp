#include <bits/stdc++.h>

using namespace std;


int main() {

    int TC;
    cin >> TC;

    while (TC--) {
        int A, B, C;
        bool found = false;
        cin >> A >> B >> C;

        for (int x = -22; x <= 22 && !found; x++) {
            for (int y = -100; y <= 100 && !found; y++) {
                for (int z = -100; z <= 100 && !found; z++) {
                    if (x != y && x != z && y != z && x + y + z == A && 
                        x * y * z == B && x * x + y * y + z * z == C) {
                        found = true;
                        cout << x << " " << y << " " << z << endl;
                    }
                }
            }
        }

        if (!found)
            cout << "No solution.\n";
    }

    return 0;
}