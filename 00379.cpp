#include <bits/stdc++.h>

using namespace std;

bool isValid(int x, int y) {
	return x >= 0 && x < 7 && y >= 0 && y < 7;
}

int dirX[] = {0, 0, 1, -1};
int dirY[] = {-1, 1, 0, 0};

int main() {
	int board[7][7] = {{0, 0, 1, 2, 3, 0, 0},
					   {0, 0, 4, 5, 6, 0, 0},
					   {7, 8, 9, 10, 11, 12, 13},
					   {14, 15, 16, 17, 18, 19, 20},
					   {21, 22, 23, 24, 25, 26, 27},
					   {0, 0, 28, 29, 30, 0, 0},
					   {0, 0, 31, 32, 33, 0, 0}};

	int n;
	cin >> n;
	cin.ignore();

	cout << "HI Q OUTPUT\n";

	while (n--) {
		bitset<34> occup;
		int val;
		bool hasNext = false;
		int lx = -1, ly = -1, nx = -1, ny = -1, ix = -1, iy = -1;
		int left = 0;

		while (cin >> val && val) {
			occup[val] = 1;
		}

		/*
		for (int i = 1; i <= 33; i++) {
			if (occup[i]) {
				cout << "occup: " << i << endl;
			}
		}
		cout << endl;
		*/

		for (int i = 0; i < 7; i++) {
			for (int j = 0; j < 7; j++) {
				if (board[i][j] == 0 || !occup[board[i][j]]) continue;

				for (int k = 0; k < 4; k++) {
					int dx = i + dirX[k];
					int dy = j + dirY[k];

					if (isValid(dx, dy) && board[dx][dy] != 0 && occup[board[dx][dy]]) {
						dx += dirX[k];
						dy += dirY[k];

						if (isValid(dx, dy) && board[dx][dy] != 0 && !occup[board[dx][dy]]) {
							hasNext = true;
							if (lx == -1) {
								lx = i;
								ly = j;
								nx = dx;
								ny = dy;
								ix = dx - dirX[k];
								iy = dy - dirY[k];
							} else if (board[dx][dy] > board[nx][ny]) {
								lx = i;
								ly = j;
								nx = dx;
								ny = dy;
								ix = dx - dirX[k];
								iy = dy - dirY[k];
							} else if (board[dx][dy] == board[nx][ny] && board[i][j] > board[lx][ly]) {
								lx = i;
								ly = j;
								nx = dx;
								ny = dy;
								ix = dx - dirX[k];
								iy = dy - dirY[k];
							}
						}
					}
				}
			}
		}

		while (hasNext) {
			occup[board[lx][ly]] = 0;
			occup[board[ix][iy]] = 0;
			occup[board[nx][ny]] = 1;

			/*
			cout << "lx: " << lx << "	ly: " << ly << endl;
			cout << "ix: " << ix << "	iy: " << iy << endl;
			cout << "nx: " << nx << "	ny: " << ny << endl;

			for (int i = 1; i <= 33; i++) {
				if (occup[i]) {
					cout << "occup: " << i << endl;
				}
			}
			cout << endl;
			*/

			hasNext = false;
			lx = ly = nx = ny = ix = iy = -1;

			for (int i = 0; i < 7; i++) {
				for (int j = 0; j < 7; j++) {
					if (board[i][j] == 0 || !occup[board[i][j]]) continue;

					for (int k = 0; k < 4; k++) {
						int dx = i + dirX[k];
						int dy = j + dirY[k];

						if (isValid(dx, dy) && board[dx][dy] != 0 && occup[board[dx][dy]]) {
							dx += dirX[k];
							dy += dirY[k];

							if (isValid(dx, dy) && board[dx][dy] != 0 && !occup[board[dx][dy]]) {
								hasNext = true;
								if (lx == -1) {
									lx = i;
									ly = j;
									nx = dx;
									ny = dy;
									ix = dx - dirX[k];
									iy = dy - dirY[k];
								} else if (board[dx][dy] > board[nx][ny]) {
									lx = i;
									ly = j;
									nx = dx;
									ny = dy;
									ix = dx - dirX[k];
									iy = dy - dirY[k];
								} else if (board[dx][dy] == board[nx][ny] && board[i][j] > board[lx][ly]) {
									lx = i;
									ly = j;
									nx = dx;
									ny = dy;
									ix = dx - dirX[k];
									iy = dy - dirY[k];
								}
							}
						}
					}
				}
			}
		}

		for (int i = 1; i <= 33; i++) {
			if (occup[i])
				left += i;
		}

		cout << left << endl;
	}

	cout << "END OF OUTPUT\n";

	return 0;
}