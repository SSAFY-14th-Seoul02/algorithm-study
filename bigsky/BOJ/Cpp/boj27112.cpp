// BOJ27112: 시간 외 근무 멈춰!
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Task {
	int deadline;
	int cost;
};

bool compareTasks(const Task& a, const Task& b) {
	return a.deadline < b.deadline;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	
	vector<Task> tasks(N);
	for (int i = 0; i < N; i++) {
		cin >> tasks[i].deadline >> tasks[i].cost;
	}

	// 마감일 순으로 정렬
	sort(tasks.begin(), tasks.end(), compareTasks);

	long current_work_load = 0;  // 현재 쌓인 업무량
	long overtime_cnt = 0;       // 필요한 시간 외 근무 횟수

	for (int i = 0; i < N; i++) {
		current_work_load += tasks[i].cost;
		int d = tasks[i].deadline;

		long avilable_weekdays = (long)(d / 7) * 5 + min(d % 7, 5);

		if (current_work_load > avilable_weekdays) {
			long needed = current_work_load - avilable_weekdays;
			overtime_cnt += needed;

			current_work_load = avilable_weekdays;
		}

		if (overtime_cnt > d) {
			cout << -1 << "\n";
			return 0;
		}
	}

	cout << overtime_cnt << "\n";

	return 0;
}