#include <string>
#include <vector>
#include <queue>
#include <algorithm>

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
            if (dist[i] != -1) continue;
            q.push(i);
            dist[i] = dist[cur] + 1;
        }
    }
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    graph.assign(n + 1, {});
    dist.assign(n + 1, -1);
    
    for (auto e : edge) {
        graph[e[0]].push_back(e[1]);
        graph[e[1]].push_back(e[0]);
    }
    
    bfs(1);
    
    int max_d = *max_element(dist.begin(), dist.end());
    for (auto i : dist) {
        if (i == max_d) answer++;
    }
    
    return answer;
}


// 다익스트라로 해결 - 아마 테케 많아지면 시간복잡도 문제 터질듯?
// #include <string>
// #include <vector>
// #include <queue>
// #include <climits>
// #include <algorithm>

// using namespace std;

// vector<vector<int>> graph;
// vector<int> dist;

// void dijkstra(int start) {
//     priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

//     dist[start] = 0;
//     pq.push({0, start});

//     while (!pq.empty()) {
//         auto [cost, cur] = pq.top();
//         pq.pop();

//         if (cost > dist[cur]) continue;

//         for (int next : graph[cur]) {
//             int nextCost = cost + 1;

//             if (dist[next] > nextCost) {
//                 dist[next] = nextCost;
//                 pq.push({nextCost, next});
//             }
//         }
//     }
// }

// int solution(int n, vector<vector<int>> edge) {
//     graph.assign(n + 1, {});
//     dist.assign(n + 1, INT_MAX);

//     for (auto e : edge) {
//         graph[e[0]].push_back(e[1]);
//         graph[e[1]].push_back(e[0]);
//     }

//     dijkstra(1);

//     int maxDist = 0;
//     int answer = 0;

//     for (int i = 1; i <= n; i++) {
//         if (dist[i] == INT_MAX) continue;

//         if (dist[i] > maxDist) {
//             maxDist = dist[i];
//             answer = 1;
//         } else if (dist[i] == maxDist) {
//             answer++;
//         }
//     }

//     return answer;
// }