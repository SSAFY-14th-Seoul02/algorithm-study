/*** 12738. 가장 긴 증가하는 부분 수열 3 ***/

/*
	LIS : 가장 긴 증가하는 부분 수열
	LIS의 원소의 수 : 가장 길었던 부분 수열의 개수
	LIS의 원소는 무엇이던 하지 않아도 상관없음
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<int> LIS;

	int N, n;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> n;

		if (LIS.empty() || n > LIS.back()) LIS.push_back(n);
		else {
			// lower_bound : 이분탐색 함수, n 이상의 값이 처음 나오는 위치를 찾음
			// it는 해당 위치를 가리키는 포인터 역할
			auto it = lower_bound(LIS.begin(), LIS.end(), n);

			*it = n;
		}
	}

	cout << LIS.size();

	return 0;
}