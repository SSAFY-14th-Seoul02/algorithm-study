// BOJ2851: 슈퍼 마리오
#include <iostream>
#include <cmath>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int total_eaten = 0;
	int score;

	for (int i = 0; i < 10; i++) {
		cin >> score;

		int current_diff = abs(100 - total_eaten);
		int next_diff = abs(100 - (total_eaten + score));

		if (current_diff >= next_diff) {
			total_eaten += score;
		} else {
			break;
		}
	}

	cout << total_eaten << "\n";

	return 0;
}