/*** 14939. 불 끄기 (P4) ***/

// 비트마스킹 연습용

/*
	첫번째 줄은 어떤 버튼이 눌리던지 상관 없음 -> 이후 줄부터 윗 줄을 끄기 위해서만 움직여야 함
	첫번째 줄에서 모든 경우의 수를 해서 가장 적은 버튼을 누를 수 있는 경우를 찾아야 함
*/

#include<iostream>

using namespace std;

void click(int x, int y);
int underClick();

bool arr[100][100];
bool origin[100][100];
char c;

int dx[5] = { 0, 0, 1, 0, -1 };
int dy[5] = { 0, 1, 0, -1, 0 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int ans = 1e9;

	// 입력
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> c;
			c != '#' ? (arr[i][j] = true) : (arr[i][j] = false);
			origin[i][j] = arr[i][j];
		}
	}

	for (int bit = 0; bit < 1024; bit++) { // 첫번째 줄에서의 경우의 수 = 1024
		int cnt = 0; // 첫번째 줄에 눌린 버튼 수

		for (int i = 0; i < 10; i++) { // 처음으로 원상복구
			for (int j = 0; j < 10; j++) {
				arr[i][j] = origin[i][j];
			}
		}

		for (int i = 0; i < 10; i++) {
			if (bit & (1 << i)) { // 각 경우의 수에서 버튼을 눌렀는지 확인
				cnt++;
				click(0, i);
			}
		}

		int remain_cnt = underClick();
		
		if (remain_cnt != -1 && ans > cnt + remain_cnt) { // 불 다 껐고, 현재 최소값보다 값이 더 작으면
			ans = cnt + remain_cnt;
		}
	}

	if (ans != 1e9) cout << ans;
	else cout << -1;

	return 0;
}

void click(int x, int y) {
	for (int d = 0; d < 5; d++) {
		int nx = x + dx[d];
		int ny = y + dy[d];

		if (nx < 0 || nx >= 10 || ny < 0 || ny >= 10) continue;

		if (arr[nx][ny]) arr[nx][ny] = false;
		else arr[nx][ny] = true;
	}
}

int underClick() { // 2번째 줄부터 버튼 클릭
	int cnt = 0;

	for (int i = 1; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (arr[i - 1][j]) { // 윗줄 버튼이 켜져있으면 버튼 클릭
				click(i, j);
				cnt++;
			}
		}
	}

	for (int i = 0; i < 10; i++) { // 버튼 불이 하나라도 켜져 있으면 실패
		for (int j = 0; j < 10; j++) {
			if (arr[i][j]) return -1;
		}
	}

	return cnt;
}