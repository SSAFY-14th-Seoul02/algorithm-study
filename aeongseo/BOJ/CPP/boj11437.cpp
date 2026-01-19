/*** 11437. LCA ***/

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

void bfs(int start);
int lca(int u, int v);

bool visited[50001];
int depth[50001];
int parent[50001];
vector<int> adj[50001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N;

	for (int i = 0; i < N - 1; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	bfs(1);

	cin >> M;

	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		cout << lca(u, v) << '\n';
	}

	return 0;
}

void bfs(int start) {
	queue<int> q;
	q.push(start);
	visited[start] = true;
	depth[start] = 0;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int next : adj[cur]) {
			if (!visited[next]) {
				visited[next] = true;
				parent[next] = cur;
				depth[next] = depth[cur] + 1;
				q.push(next);
			}
		}
	}
}

int lca(int u, int v) {
	if (depth[u] < depth[v]) swap(u, v); // u가 더 깊도록

	while (depth[u] != depth[v]) { // 깊이 맞추기
		u = parent[u];
	}

	while (u != v) { // 공통 조상 찾기
		u = parent[u];
		v = parent[v];
	}

	return u;
}