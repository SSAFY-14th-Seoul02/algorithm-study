/*** 1113. 수영장 만들기 ***/

#include<iostream>
#include<queue>
#include<vector>
#include<string>

using namespace std;

struct Node{
    int h, i, j;
};

bool operator <(Node a, Node b){
    if(a.h != b.h) return a.h > b.h;
}

int di[4] = {0, 1, 0, -1};
int dj[4] = {1, 0, -1, 0};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, water = 0;
    cin >> N >> M;

    vector<vector<int>> ground(N, vector<int>(M, 0));
    for (int i = 0; i < N; i++){
        string line;
        cin >> line;
        for (int j = 0; j < M; j++){
            ground[i][j] = line[j] - '0';
        }
    }

    priority_queue<Node> pq;
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    for (int j = 0; j < M; j++){
        pq.push({ground[0][j], 0, j});
        pq.push({ground[N - 1][j], N - 1, j});
        visited[0][j] = true;
        visited[N - 1][j] = true;
    }

    for (int i = 1; i < N - 1; i++){
        pq.push({ground[i][0], i, 0});
        pq.push({ground[i][M - 1], i, M - 1});
        visited[i][0] = true;
        visited[i][M - 1] = true;
    }

    while(!pq.empty()){
        Node cur = pq.top();
        pq.pop();

        for (int d = 0; d < 4; d++){
            int ni = cur.i + di[d];
            int nj = cur.j + dj[d];

            if(ni < 0 || ni >= N || nj < 0 || nj >= M || visited[ni][nj]) continue;
            
            if(cur.h > ground[ni][nj]) {
                water += cur.h - ground[ni][nj];
                ground[ni][nj] = cur.h;
            }
            pq.push({ground[ni][nj], ni, nj});
            visited[ni][nj] = true;
        }
    }

    cout << water;

    return 0;
}