/*
PGM42627. 디스크 컨트롤러

[문제 링크]
https://school.programmers.co.kr/learn/courses/30/lessons/42627

[풀이 전략]
- SJF(Shortest Job First) 스케줄링: 매 순간 '도착해 있는' 작업 중 소요시간이 가장 짧은 것을 먼저 처리하면 평균 대기시간이 최소가 된다.
- '소요시간이 가장 짧은 작업'을 빠르게 꺼내기 위해 최소 힙을 사용한다.
- 총 대기시간 = Σ(완료시각 - 요청시각) = Σ완료시각 - Σ요청시각
  → 요청시각 합은 미리 구하고, 완료시각 합은 처리하면서 누적한다.
*/

#include <vector>
#include <queue>
#include <algorithm>
#include <functional> 

using namespace std;

int solution(vector<vector<int>> jobs) {

  // 소요시간 기준 최소 힙
  priority_queue<int, vector<int>, greater<int>> pq;

  int current_time = 0;   // 현재 시각
  int idx = 0;            // 아직 큐에 넣지 않은 작업을 가리키는 포인터
  int n = jobs.size();    // 전체 작업 수
  int done = 0;           // 처리 완료한 작업 수
  long long total = 0LL;  // Σ완료시각
  int answer = 0;

  // 요청시각 기준 오름차순 정렬 → idx 포인터로 도착 순서대로 훑기 위함
  sort(jobs.begin(), jobs.end());

  // Σ요청시각: 정렬 순서와 무관하므로 미리 한 번에 계산
  long long requestSum = 0;
  for (auto& job : jobs) {
    requestSum += job[0];
  }

  // 모든 작업을 처리할 때까지 반복
  while (done < n) {

    // [1] 현재 시각까지 '도착한' 작업의 소요시간을 모두 큐에 넣는다.
    //     jobs가 정렬되어 있으므로 idx는 되돌아오지 않고 한 방향으로만 전진.
    //     (idx < n을 먼저 검사 → 단축 평가로 범위 밖 접근 방지)
    while (idx < n && jobs[idx][0] <= current_time) {
      pq.push(jobs[idx][1]);   // jobs[idx][1] = 소요시간
      idx++;
    }

    if (pq.empty()) {
      // [2] 큐가 비었다 = 아직 도착한 작업이 없는 '공백 시간'.
      //     현재 시각을 다음 작업의 요청시각으로 점프시킨다.
      current_time = jobs[idx][0];
    } else {
      // [3] 큐에 작업이 있다 = 가장 짧은 작업을 꺼내 처리.
      int duration = pq.top();    // 가장 짧은 소요시간 확인
      pq.pop();                   // 큐에서 제거
      current_time += duration;   // 작업 완료 시각으로 갱신
      total += current_time;      // Σ완료시각에 누적
      done++;                     // 처리 완료 카운트 +1
    }
  }

  // 총 대기시간 = Σ완료시각 - Σ요청시각, 이를 작업 수로 나눠 평균(버림)
  answer = (total - requestSum) / n;
  return answer;
}