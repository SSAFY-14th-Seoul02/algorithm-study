/*
BOJ2294 : 동전 2 (G5)

해결 방법 : 있는 동전으로 작은 동전부터 큰 동전까지 갱신하면서, 최소로 드는 동전 개수로 교체하기
ex) 1로 걸리는 만큼 구하기 -> 1, 2, 3, 4, 5, 6
2로 교체하기 -> 1, 1, 2, 2, 3, 3
5로 교체하기 -> 1, 1, 2, 2, 1, 2
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int dp[10001] = { 0, };
int main() {
	int n, k;
	cin >> n>>k; 
	vector<int>money(n+1);
	for (int i = 1; i <= n; i++) {
    cin >> money[i];
  }
	for (int i = 1; i <= k; i++) {
    dp[i] = 10001; 
  }
	for (int i = 1; i <= n; i++) { 
		for (int j = money[i]; j <= k; j++) { 
			dp[j] = min(dp[j], dp[j - money[i]] + 1);
		}
	}
	if (dp[k] == 10001) {
    cout << -1 << '\n';
  } else {
    cout << dp[k] << '\n';
  }
}