/*** 11779. 최소비용 구하기 2 ***/

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

void dijkstra(int start);
void backtrack(int end);

const long long INF = 1e18;
vector<pair<int, int>> adj[1001];
vector<long long> dists;
vector<int> parent;
vector<int> path;
int n, m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({ v, w });
	}

	int start, end;
	cin >> start >> end;

	dijkstra(start);
	cout << dists[end] << '\n';

	backtrack(end);
	
	cout << path.size() << '\n';
	for (int i = 0; i < path.size(); i++) {
		cout << path[i] << ' ';
	}

	return 0;
}

void dijkstra(int start) {
	priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
	dists.assign(n + 1, INF);
	parent.assign(n + 1, 0);

	dists[start] = 0;
	pq.push({ 0, start });

	while (!pq.empty()) {
		auto [dist, cur] = pq.top();
		pq.pop();

		if (dist > dists[cur]) continue;

		for (auto& edge : adj[cur]) {
			auto [next, w] = edge;

			if (dists[next] <= dists[cur] + w) continue;

			dists[next] = dists[cur] + w;
			parent[next] = cur; // 경로 저장
			pq.push({ dists[next], next });
		}
	}
}

void backtrack(int end) { // 경로 역추적
	for (int i = end; i != 0; i = parent[i]) path.push_back(i);
	reverse(path.begin(), path.end());
}