#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    
    queue<int> q;
    for (auto i : priorities) {
        q.push(i);
    }
    
    sort(priorities.rbegin(), priorities.rend());
    
    while (true) {
        if (q.front() == priorities[0]) {
            q.pop();
            priorities.erase(priorities.begin());
            answer++;
            
            if (location == 0) return answer;
            else location--;
        } else {
            q.push(q.front());
            q.pop();
            location--;
            
            if (location < 0) location = q.size() - 1;
        }
    }
    
    return answer;
}