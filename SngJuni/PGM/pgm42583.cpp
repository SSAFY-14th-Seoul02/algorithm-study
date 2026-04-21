#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    
    int sum = 0, next = 0;
    
    queue<int> q;
    for (int i = 0; i < bridge_length; i++) {
        q.push(0);
    }
    
    while (!q.empty()) {
        sum -= q.front();
        q.pop();
        answer++;
        
        if (next < truck_weights.size()) {
            if (sum + truck_weights[next] <= weight) {
                sum += truck_weights[next];
                q.push(truck_weights[next]);
                next++;
            } else {
                q.push(0);
            }
        }
    }
    
    return answer;
}
