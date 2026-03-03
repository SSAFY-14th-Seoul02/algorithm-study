/*** 29703. 펭귄의 하루 ***/

#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

void bfs(int si, int sj, int visited[1001][1001]);

int N, M, si, sj, hi, hj, mindist = 987654321;
char village[1001][1001];
int sf[1001][1001], hf[1001][1001];
vector<pair<int, int>> fish;
int di[4] = {0, 1, 0, -1};
int dj[4] = {1, 0, -1, 0};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            cin >> village[i][j];
            if(village[i][j] == 'S') {
                si = i;
                sj = j;
            }
            else if(village[i][j] == 'F'){
                fish.push_back({i, j});
            }
            else if(village[i][j] == 'H'){
                hi = i;
                hj = j;
            }
        }
    }

    bfs(si, sj, sf);
    bfs(hi, hj, hf);

    for(auto [fi, fj] : fish){
        if(sf[fi][fj] > 0 && hf[fi][fj] > 0) mindist = min(mindist, sf[fi][fj] + hf[fi][fj] - 2);
    }

    if(mindist == 987654321) mindist = -1;

    cout << mindist;

    return 0;
}

void bfs(int si, int sj, int visited[1001][1001]){
    queue<pair<int, int>> q;

    visited[si][sj] = 1;
    q.push({si, sj});

    while(!q.empty()){
        auto [ti, tj] = q.front();
        q.pop();

        for (int d = 0; d < 4; d++){
            int ni = ti + di[d];
            int nj = tj + dj[d];
            if(ni < 0 || ni >= N || nj < 0 || nj >= M || visited[ni][nj]) continue;

            if(village[ni][nj] == 'D') continue;
            q.push({ni, nj});
            visited[ni][nj] = visited[ti][tj] + 1;
        }
    }
}