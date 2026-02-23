/*** 11967. 불켜기 ***/

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int bfs(int si, int sj);

int N, M;
int di[4] = {0, 1, 0, -1};
int dj[4] = {1, 0, -1, 0};
vector<vector<bool>> lights;
vector<vector<vector<pair<int, int>>>> adj;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    adj.assign(N + 1, vector<vector<pair<int, int>>>(N + 1));
    lights.assign(N + 1, vector<bool>(N + 1, false));
    lights[1][1] = true;

    for (int i = 0; i < M; i++){
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        adj[x][y].push_back({a, b});
    }

    int ans = bfs(1, 1);

    cout << ans;

    return 0;
}

int bfs(int si, int sj){
    int ans = 0;
    queue<pair<int, int>> q;
    vector<vector<bool>> visited(N+1, vector<bool>(N+1, false));
    visited[si][sj] = true;
    q.push({si, sj});

    while(!q.empty()){
        int ti = q.front().first;
        int tj = q.front().second;
        q.pop();

        for(auto& [i, j] : adj[ti][tj]){
            if(lights[i][j]) continue;
            lights[i][j] = true;

            for (int d = 0; d < 4; d++){
                int ni = i + di[d];
                int nj = j + dj[d];

                if(ni < 1 || ni > N || nj < 1 || nj > N || !visited[ni][nj]) continue;
                q.push({i, j});
                visited[i][j] = true;
                break;
            }
        }

        for (int d = 0; d < 4; d++){
            int ni = ti + di[d];
            int nj = tj + dj[d];

            if(ni < 1 || ni > N || nj < 1 || nj > N) continue;

            if(visited[ni][nj] || !lights[ni][nj]) continue;

            q.push({ni, nj});
            visited[ni][nj] = true;
        }
    }

    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= N; j++){
            if(lights[i][j]) ans++;
        }
    }

    return ans;
}