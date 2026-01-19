/*** 2206. 벽 부수고 이동하기 ***/

#include<iostream>
#include<string>
#include<queue>
#include<tuple>
using namespace std;

int bfs();

int N, M;
int di[4] = { 0, 1, 0, -1 };
int dj[4] = { 1, 0, -1, 0 };
queue<tuple<int, int, int>> q;
int map[1001][1001] = { 0, };
int visited[1001][1001][2] = { 0, }; // [행][열][벽 부숨 여부]

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	string line;
	for (int i = 0; i < N; i++) {
		cin >> line;
		for (int j = 0; j < M; j++) {
			map[i][j] = line[j] - '0';
		}
	}

	cout << bfs();

	return 0;
}

int bfs() {
	q.push({ 0, 0, 0 });
	visited[0][0][0] = 1;

	while (!q.empty()) {
		auto[ti, tj, broke] = q.front();
		q.pop();

		if (ti == N - 1 && tj == M - 1) return visited[ti][tj][broke]; // (N, M) 위치에 도달하면 해당 칸의 이동 횟수 반환

		for (int d = 0; d < 4; d++) {
			int ni = ti + di[d];
			int nj = tj + dj[d];

			if (ni < 0 || ni >= N || nj < 0 || nj >= M) continue;
			if (!map[ni][nj] && !visited[ni][nj][broke]) { // 지나갈 수 있는 길이고 방문한 적 없으면
				visited[ni][nj][broke] = visited[ti][tj][broke] + 1; // 현재 칸의 이동 횟수 + 1 저장
				q.push({ ni, nj, broke });
			}
			if (map[ni][nj] && !broke && !visited[ni][nj][1]) { // 벽이고 벽을 부순 적이 없으며 방문한 적 없으면
				visited[ni][nj][1] = visited[ti][tj][broke] + 1;	// 현재 칸의 이동 횟수 + 1 저장
				q.push({ ni, nj, 1 });
			}
		}
	}

	return -1; // 목적지에 도달하지 못하고 갈 곳이 없으면 -1 반환
}