/*** 8980. 택배 ***/

// 도착지 기준으로 오름차순 정렬
// 각 마을 구간의 남은 용량 표시
// 실어야 할 택배 개수와 가능한 용량 비교하여 최소값으로 택배 싣기

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct Route {
	int start;
	int end;
	int count;
};

bool compareRoute(const Route& a, const Route& b) {
	if (a.end != b.end) return a.end < b.end; // 1순위 : 도착지 오름차순
	if (a.start != b.start) return a.start < b.start; // 2순위 : 출발지 오름차순
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, C, M, ans = 0;
	cin >> N >> C >> M;

	vector<Route> boxes;

	for (int i = 0; i < M; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		boxes.push_back({ u, v, w });
	}

	sort(boxes.begin(), boxes.end(), compareRoute);

	vector<int> capacity(N + 1, C);

	// 상자 목록 순회
	for (int i = 0; i < M; i++) {
		int start = boxes[i].start;
		int end = boxes[i].end;
		int count = boxes[i].count;

		for (int j = start; j < end; j++) { // 실을 수 있는 최소값 찾기 (start, end - 1) -> 도착지에서는 바로 택배 내리기 때문
			count = min(capacity[j], count);
		}

		if (!count) continue;

		for (int j = start; j < end; j++) { // 실은 만큼 각 구간의 용량 감소
			capacity[j] -= count;
		}

		ans += count; // 실은 택배 개수 증가
	}

	cout << ans;


	return 0;
}