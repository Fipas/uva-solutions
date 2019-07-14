#include <bits/stdc++.h>

using namespace std;


int main() {

    unsigned int N, L, U;

    while (cin >> N >> L >> U) {
        unsigned int MASK = ~N;

        for (int i = 31; i >= 0; i--) {
            //cout << "MASK: " << (bitset<8>) MASK << endl;
            //cout << "L: " << (bitset<8>) L << endl;
            //cout << "U: " << (bitset<8>) U << endl;
            if ((MASK >> i) > (U >> i))
                MASK &= ~(1 << i);
            else if ((MASK >> i) < (L >> i))
                MASK |= (1 << i);
        }

        cout << MASK << endl;
    }

    return 0;
}