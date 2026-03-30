/*** 2448. 별 찍기 - 11 ***/

#include<iostream>

using namespace std;

void draw(int n, int x, int y);

char board[3072][6144];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 2 * N; j++) {
			board[i][j] = ' ';
		}
	}

	draw(N, 0, N - 1);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 2 * N; j++) {
			cout << board[i][j];
		}
		cout << '\n';
	}

	return 0;
}

void draw(int n, int x, int y) {
	if (n == 3) {
		board[x][y] = '*';
		board[x + 1][y - 1] = '*';
		board[x + 1][y + 1] = '*';
		for (int i = -2; i < 3; i++) {
			board[x + 2][y + i] = '*';
		}
		return;
	}
	draw(n / 2, x, y);
	draw(n / 2, x + n / 2, y - n / 2);
	draw(n / 2, x + n / 2, y + n / 2);
}