/*** 가장 먼 노드 (L3) ***/

#include <string>
#include <vector>
#include <queue>

using namespace std;


int solution(int n, vector<vector<int>> edge) {
    int answer = 0, cnt = 0;
    vector<int> graph[n + 1], visited(n + 1, 0);
    queue<int> q;
    
    for(int i=0; i<edge.size(); i++){
        graph[edge[i][0]].push_back(edge[i][1]);
        graph[edge[i][1]].push_back(edge[i][0]);
    }
    
    visited[1] = 1;
    q.push(1);
    
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        
        for(const auto& n : graph[cur]){
            if(!visited[n]){
                visited[n] = visited[cur] + 1;
                q.push(n);
                if(cnt < visited[n]) cnt = visited[n];
            }
        }
    }
    
    for(int i=0; i<n+1; i++){
        if(visited[i] == cnt) answer++;
    }
    
    return answer;
}