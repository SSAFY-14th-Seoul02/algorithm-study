/*** 1766. 문제집 ***/

#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	vector<int> adj[32001]; // 인접 리스트
	int indegree[32001] = { 0, }; // 선행 문제 개수
	priority_queue<int, vector<int>, greater<int>> pq;

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		indegree[b]++; // b를 풀기 전에 a를 먼저 풀어야 함
	}

	for (int i = 1; i <= N; i++) {
		if (!indegree[i]) pq.push(i);
	}

	while (!pq.empty()) {
		int cur = pq.top();
		pq.pop();

		cout << cur << ' ';

		for (int next : adj[cur]) {
			indegree[next]--; // cur를 풀었으므로 다음 문제들의 선행 문제 개수 감소
			
			if (!indegree[next]) pq.push(next); // 선행 문제가 없으면 우선순위 큐에 추가
		}

	}

	return 0;
}