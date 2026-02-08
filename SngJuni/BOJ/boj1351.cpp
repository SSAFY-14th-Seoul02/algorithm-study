#include <iostream>
#include <unordered_map>

using namespace std;

long long N, P, Q;
unordered_map<long long, long long> dp;

long long dfs(long long x) {
    if (x == 0) return 1;
    if (dp.count(x)) return dp[x];

    return dp[x] = dfs(x / P) + dfs(x / Q);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> P >> Q;

    cout << dfs(N) << '\n';

    return 0;
}
