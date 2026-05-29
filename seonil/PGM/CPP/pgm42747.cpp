/*
PGM42747. H-index

[문제 링크]
https://school.programmers.co.kr/learn/courses/30/lessons/42747
*/

#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0; // H-index 값 (조건을 만족한 논문 수)

    // 인용 횟수를 내림차순으로 정렬
    sort(citations.begin(), citations.end(), greater<int>());

    // 앞에서부터 순회: i번째까지 보면 "i+1편의 논문"을 검토한 상태
    for (int i = 0; i < citations.size(); i++) {
        // citations[i] < i+1 이면 조건이 깨짐
        // → "i+1번 이상 인용된 논문이 i+1편"을 만족 못 하는 순간이므로 멈추기
        if(citations[i] < i+1){
            break;
        }
        // i+1편의 논문이 모두 i+1번 이상 인용됨 → H-index 갱신
        answer++;
    }
    return answer;
}