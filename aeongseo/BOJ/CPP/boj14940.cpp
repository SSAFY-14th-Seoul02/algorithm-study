/*** 14940. 쉬운 최단거리 ***/

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

void bfs(int i, int j);

int n, m;
vector<vector<int>> map, visited;
int di[4] = {0, 1, 0, -1};
int dj[4] = {1, 0, -1, 0};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    map.resize(n, vector<int>(m));
    visited.assign(n, vector<int>(m, -1));

    int si, sj;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> map[i][j];
            if(map[i][j] == 2) {
                si = i;
                sj = j;
            }
            else if(!map[i][j]){
                visited[i][j] = 0;
            }
        }
    }

    bfs(si, sj);

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout << visited[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}

void bfs(int i, int j){
    queue<pair<int, int>> q;
    q.push({i, j});
    visited[i][j] = 0;

    while(!q.empty()){
        auto [ti, tj] = q.front();
        q.pop();

        for (int d = 0; d < 4; d++){
            int ni = ti + di[d];
            int nj = tj + dj[d];

            if(ni < 0 || ni >= n || nj < 0 || nj >= m || visited[ni][nj] != -1 || !map[ni][nj]) continue;

            visited[ni][nj] = visited[ti][tj] + 1;
            q.push({ni, nj});
        }
    }
}