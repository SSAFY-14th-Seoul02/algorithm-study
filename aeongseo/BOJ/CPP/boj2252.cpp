/*** 2252. 줄 세우기 ***/

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int indegree[32001]; // 진입차수
vector<int> adj[32001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	queue<int> q;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		indegree[b]++;
	}

	for (int i = 1; i <= n; i++) {
		if (!indegree[i]) q.push(i); // 진입차수가 0이면 큐에 삽입
	}

	while (!q.empty()) {
		int cur = q.front();
		cout << cur << ' '; // 줄 세움
		q.pop();

		for (auto& next : adj[cur]) { // 현 번호 뒤에 와야하는 번호들의 진입차수 1씩 줄임
			indegree[next]--;
			if (!indegree[next]) q.push(next); // 새롭게 진입차수가 0이 되면 큐에 삽입
		}
	}

	return 0;
}