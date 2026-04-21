/*
PGM12939. 최댓값과 최솟값

[문제 링크]
https://school.programmers.co.kr/learn/courses/30/lessons/12939

*/

#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

string solution(string s) {

    stringstream ss(s);
    vector<int> nums;
    int n, maxNum, minNum;

    // 문자열 파싱하여 정수 배열 nums로 변환
    while (ss >> n) {
      nums.push_back(int(n));
    }

    // 정수 배열 nums에서 최댓값/최솟값 찾기
    minNum = *min_element(nums.begin(), nums.end());
    maxNum = *max_element(nums.begin(), nums.end());
    
    // 출력 형식에 맞춰서 정답 반환
    string answer = "";
    answer = to_string(minNum) + " " + to_string(maxNum);
    return answer;
}