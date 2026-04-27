#include <string>
#include <vector>

using namespace std;

/*
현재 난이도 = diff, 현재 퍼즐 시간 = time_cur, 이전 퍼즐 시간 = time_prev, 숙련도 = level, 전체 제한시간 = limit

if diff <= level : solved
if diff > level : diff - level 번 fail -> 직전 퍼즐부터 solve


start = 1, end = 100,000

mid 설정

*/

int solution(vector<int> diffs, vector<int> times, long long limit) {
    long long answer = 100000;
    long long left = 1, right = 100000;
    long long level = (left + right) / 2;
    while(left < right){    // left와 right가 같아질 때까지 반복
        level = (left + right) / 2;   // mid 계산
        // 소요시간 계산
        long long total = 0;
        for(int i=0; i<diffs.size(); i++){
            if(level >= diffs[i]) total += times[i];
            else{
                long long fail = diffs[i] - level;
                if(i == 0) total += (fail + 1) * times[i];
                else total += fail * (times[i] + times[i-1]) + times[i];
            }
        }
        if(total > limit) left = level + 1; // 소요시간이 제한시간보다 크면 left = mid
        
        if(total <= limit) {    // 소요시간이 제한시간보다 작으면
            if(level < answer) answer = level;  // 소요시간 저장
            right = level;  // right = mid
        }
    }
    
    return answer;
}