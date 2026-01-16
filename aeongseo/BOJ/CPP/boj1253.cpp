/*** 1253. 좋다 ***/

#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, A[20001] = { 0, }, ans = 0;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	sort(A, A + N); // 오름차순 정렬

	for (int target = 0; target < N; target++) {
		int i = 0; // 양 끝에 포인터 설정
		int j = N - 1;
		while (i < j) {
			if (i == target) i++;
			else if (j == target) j--;
			if (i == j) break;
			if (A[i] + A[j] == A[target]) {
				ans++;
				break;
			}
			else if (A[i] + A[j] > A[target]) j--;
			else if (A[i] + A[j] < A[target]) i++;
 		}
	}

	cout << ans;

	return 0;
}