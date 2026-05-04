#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

void bfs(int start, const vector<vector<int>> &c, vector<bool> &visited) {
    queue<int> q;
    q.emplace(start);
    visited[start] = true;
    
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        
        for (int i = 0; i < c[cur].size(); i++) {
            if (!visited[i] && c[cur][i] == 1) {
                cout << i << ' ';
                q.emplace(i);
                visited[i] = true;
            }
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            bfs(i, computers, visited);
            answer++;
        }
    }

    return answer;
}