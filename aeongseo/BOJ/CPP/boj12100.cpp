/*** 12100. 2048 (Easy) ***/

/*
    현재 보드를 복사 -> 한 방향으로 밂 -> 또 다음 이동(최대 5번)
    -> 돌아와서 다른 방향으로 밂

    좌측 밀기 로직
    - 0을 제외한 숫자만 큐에 저장
    - 첫 값은 보드에 바로 저장
    - 현재 값과 이전 값이 같으면 이전 값에 x2
    - 다르면 다음 칸에 현재 값 저장
    - 줄마다 반복
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

vector<vector<int>> move_block(vector<vector<int>> board);
vector<vector<int>> rotate(vector<vector<int>> board);
void solve(int depth, vector<vector<int>> cur_board);

int N, max_block = 0;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<vector<int>> board;
    
    cin >> N;
    board.assign(N, vector<int>(N, 0));

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cin >> board[i][j];
        }
    }

    solve(0, board);

    cout << max_block;

    return 0;
}

// 왼쪽으로 밀기
vector<vector<int>> move_block(vector<vector<int>> board){
    for (int i = 0; i < N; i++){
        queue<int> q;
        for (int j = 0; j < N; j++) {
            if(board[i][j]) q.push(board[i][j]);
            board[i][j] = 0;
        }

        int idx = 0;
        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            
            // 보드에 넣으려는 칸이 빈 경우
            if(!board[i][idx]) board[i][idx] = cur;
            // 숫자가 같은 경우
            else if (board[i][idx] == cur) {
                board[i][idx] *= 2;
                idx++;
            }
            // 숫자가 다른 경우
            else {
                idx++;
                board[i][idx] = cur;
            }
        }
    }

    return board;
}


// 보드 회전
vector<vector<int>> rotate(vector<vector<int>> board) {
    vector<vector<int>> rotated_board(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            rotated_board[j][N - 1 - i] = board[i][j];
        }
    }

    return rotated_board;
}

// 백트래킹
void solve(int depth, vector<vector<int>> cur_board){
    if (depth == 5) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N;j++) {
                max_block = max(max_block, cur_board[i][j]);
            }
        }
        return;
    }

    vector<vector<int>> temp = cur_board;
    for (int d = 0; d < 4; d++) {
        solve(depth + 1, move_block(temp));
        temp = rotate(temp);
    }
}