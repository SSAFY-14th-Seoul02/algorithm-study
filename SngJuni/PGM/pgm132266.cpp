#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> graph;
vector<int> dist;

void bfs(int s) {
    queue<int> q;
    q.push(s);
    dist[s] = 0;
    
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        
        for (auto i : graph[cur]) {
            if (dist[i] == -1) {
                q.push(i);
                dist[i] = dist[cur] + 1;
            }
        }
    }
}

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    
    graph.assign(n + 1, {});
    dist.assign(n + 1, -1);
    
    for (auto r : roads) {
        graph[r[0]].push_back(r[1]);
        graph[r[1]].push_back(r[0]);
    }
    
    bfs(destination);

    for (auto source : sources) {
        answer.push_back(dist[source]);
    }
    
    return answer;
}