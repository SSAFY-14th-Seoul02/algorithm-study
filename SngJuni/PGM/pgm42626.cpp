#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    priority_queue<int, vector<int>, greater<>> pq;
    for (auto s : scoville) {
        pq.push(s);
    }
    
    while (pq.top() < K) {
        if (pq.size() <= 1) {
            answer = -1;
            break;
        }
        int s1 = pq.top();
        pq.pop();
        
        int s2 = pq.top();
        pq.pop();
        
        pq.push(s1 + s2 * 2);
        answer++;
    }
    
    return answer;
}