/*** 더 맵게 (L2) ***/

#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for(int i=0;i<scoville.size();i++){
        pq.push(scoville[i]);
    }
    
    while(!pq.empty()){
        int cur = pq.top();
        pq.pop();
        
        if(cur >= K) break;
        else{
            if(pq.empty()) break;
            else{
                int next = pq.top();
                pq.pop();
            
                pq.push((cur + (next * 2)));
                answer++;
            }
        }
    }
    if(pq.top() < K) answer = -1;
    return answer;
}