#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string name) {
    int answer = 0;
    int n = name.size();

    for (char c : name) {
        answer += min(c - 'A', 'Z' - c + 1);
    }

    int move = n - 1;

    for (int i = 0; i < n; i++) {
        int next = i + 1;

        while (next < n && name[next] == 'A') {
            next++;
        }

        int right_then_left = i * 2 + (n - next);

        int left_then_right = (n - next) * 2 + i;

        move = min(move, min(right_then_left, left_then_right));
    }

    answer += move;

    return answer;
}