/*** 11000. 강의실 배정 ***/

/*
	시작시간 기준으로 정렬한다.
	처음 강의실의 종료시간을 우선순위큐에 넣는다.
	다음 강의의 시작 시간이 우선순위큐의 종료시간보다 작으면 큐에 종료시간을 넣는다.
	다음 강의의 시작 시간이 우선순위큐의 종료시간보다 같거나 크면 우선순위 큐의 종료시간을 빼고, 종료시간을 넣는다.
	마지막에 큐에 남은 값의 개수가 강의실 개수이다.
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	vector<pair<int, int>> lectures(N);
	for (int i = 0; i < N; i++) {
		cin >> lectures[i].first >> lectures[i].second;
	}

	sort(lectures.begin(), lectures.end());

	priority_queue<int, vector<int>, greater<int>> pq;

	pq.push(lectures[0].second);

	for (int i = 1; i < N; i++) {
		if (pq.top() <= lectures[i].first) pq.pop();
		pq.push(lectures[i].second);
	}

	cout << pq.size();


	return 0;
}