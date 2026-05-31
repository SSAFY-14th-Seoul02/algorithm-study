#include <vector>
#include <algorithm>

using namespace std;

int answer = 0;
int visited[8] = {0, };

void dfs(int depth, int p, vector<vector<int>> &d) {
    answer = max(answer, depth);

    for (int i = 0; i < d.size(); i++) {
        if (!visited[i] && p >= d[i][0]) {
            visited[i] = true;
            dfs(depth + 1, p - d[i][1], d);
            visited[i] = false;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    dfs(0, k, dungeons);

    return answer;
}