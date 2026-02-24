/*** 3109. 빵집 ***/

/*
    dfs로 왼쪽에서 오른쪽으로 이동하는 데 무조건 오른쪽 위 대각선, 오른쪽, 오른쪽 아래 대각선 순으로 이동한다.
    세 부분 모두 길이 막혀있으면 되돌아간다.
*/

#include<iostream>
#include<vector>

using namespace std;

bool dfs(int si, int sj);

vector<vector<bool>> arr, visited;
int R, C, cnt = 0;
int di[3] = {-1, 0, 1};
int dj[3] = {1, 1, 1};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> R >> C;

    arr.assign(R, vector<bool>(C, false));
    visited.assign(R, vector<bool>(C, false));

    for (int i = 0; i < R; i++){
        for (int j = 0; j < C; j++){
            char c;
            cin >> c;
            if(c == 'x') arr[i][j] = true;
        }
    }

    for (int i = 0; i < R; i++){
        dfs(i, 0);
    }

    cout << cnt;

    return 0;
}

bool dfs(int si, int sj){
    visited[si][sj] = true;
    if(sj == C - 1) {
        cnt++;
        return true;
    }

    for (int d = 0; d < 3; d++){
        int ni = si + di[d];
        int nj = sj + dj[d];

        if(ni < 0 || ni >= R || nj >= C) continue;

        if(arr[ni][nj] || visited[ni][nj]) continue;

        if(dfs(ni, nj)) return true;
    }

    return false;
}