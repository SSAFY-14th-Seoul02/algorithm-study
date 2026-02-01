/*
BOJ10026 : 적록색약 (G5)

해결 방법 : 
bfs 코드를 적록색약 버전과 일반 버전으로 만들어서 해결

메모 : 
시간과 메모리를 줄일 수 있는 방법
1. 적록색약 버전으로 arr을 만들어서 돌리면 bfs를 하나 더 만드는 수고를 줄일 수 있음
2. 첫번째 탐색이 끝나면 visited 배열을 초기화 해서 다시 사용하는 방식으로 메모리를 줄일 수 있음
3. 상하좌우 좌표를 따로 빼놓으면 미세하게 시간을 단축할 수 있음
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;
char arr[101][101];
int see[101][101]; 
int si_list[] = {0, 0, 1, -1};
int sj_list[] = {1, -1, 0, 0};

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    see[x][y] = 1;
    char color = arr[x][y];

    while (!q.empty()) {
        int ti = q.front().first;  
        int tj = q.front().second; 
        q.pop();

        for (int i = 0; i < 4; i++) {
            int si = si_list[i]; 
            int sj = sj_list[i]; 
            
            int ni = ti + si;    
            int nj = tj + sj;    

            if (0 <= ni && ni < n && 0 <= nj && nj < n) {
                if (arr[ni][nj] == color && !see[ni][nj]) {
                    see[ni][nj] = 1;
                    q.push({ni, nj});
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!see[i][j]) {
                bfs(i, j);
                cnt++;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] == 'G') arr[i][j] = 'R';
            see[i][j] = 0; 
        }
    }
    int no_cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!see[i][j]) {
                bfs(i, j);
                no_cnt++;
            }
        }
    }
    cout << cnt << " " << no_cnt << "\n";
    return 0;
}