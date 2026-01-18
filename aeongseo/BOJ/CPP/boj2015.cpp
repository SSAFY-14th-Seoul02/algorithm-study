/*** 2015 수들의 합 4 ***/

/*
	누적합 짱어렵다
*/

#include<iostream>
#include<map>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, K;
	long long sum = 0, ans = 0;
	map<long long, int> cnt;

	cin >> N >> K;

	cnt[0] = 1; // 아무것도 고르지 않았을 때 부분합은 0, 이것도 카운트 해줘야 함

	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		sum += n; // 1부터 j까지의 누적합 S[j]
		
		ans += cnt[sum - K]; // S[j] - K = S[i-1] => 1부터 i까지의 누적합이 존재했다면 그 수만큼 더함

		cnt[sum]++; // S[j]을 카운트하고 다음으로 넘어감
	}
	
	cout << ans;


	return 0;
}