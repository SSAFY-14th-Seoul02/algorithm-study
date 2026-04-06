/*
BOJ14442. 벽 부수고 이동하기 2

[문제]
N×M의 행렬로 표현되는 맵이 있다. 맵에서 0은 이동할 수 있는 곳을 나타내고, 1은 이동할 수 없는 벽이 있는 곳을 나타낸다.
당신은 (1, 1)에서 (N, M)의 위치까지 이동하려 하는데, 이때 최단 경로로 이동하려 한다.
최단경로는 맵에서 가장 적은 개수의 칸을 지나는 경로를 말하는데, 이때 시작하는 칸과 끝나는 칸도 포함해서 센다.
만약에 이동하는 도중에 벽을 부수고 이동하는 것이 좀 더 경로가 짧아진다면, 벽을 K개 까지 부수고 이동하여도 된다.
한 칸에서 이동할 수 있는 칸은 상하좌우로 인접한 칸이다.
맵이 주어졌을 때, 최단 경로를 구해 내는 프로그램을 작성하시오.

[입력]
첫째 줄에 N(1 ≤ N ≤ 1,000), M(1 ≤ M ≤ 1,000), K(1 ≤ K ≤ 10)이 주어진다.
다음 N개의 줄에 M개의 숫자로 맵이 주어진다. (1, 1)과 (N, M)은 항상 0이라고 가정하자.

[출력]
첫째 줄에 최단 거리를 출력한다. 불가능할 때는 -1을 출력한다.
*/

#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

// 상하좌우 델타 배열
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

// BFS에서 큐에 넣을 상태 정보
struct State {
    int y, x, broken, dist;
};

// 목적지까지 K개의 벽부수기 카운트를 포함해 최단 거리를 반환하는 함수
int bfs(State start, int N, int M, int K, const vector<vector<int>>& matrix){
  
  // 3차원 visited 배열: visited[y][x][k] = (y,x)에 벽을 k개 부수고 방문한 적 있는지
  vector<vector<vector<bool>>> visited(N, vector<vector<bool>>(M, vector<bool>(K+1, false)));
  queue<State> q;

  // BFS 준비
  q.push(start);
  auto [sy, sx, sb, sd] = start;
  visited[sy][sx][sb] = true;

  // BFS 시작
  while (!q.empty()) {
    auto [cur_y, cur_x, cur_broken, cur_dist] = q.front();
    q.pop();

    // 도착 조건: (N-1, M-1)에 도착하면 현재 거리 반환, BFS이므로 처음 도착한 것이 곧 최단거리!
    if (cur_y == N-1 && cur_x == M-1){
      return cur_dist;
    }

    // 상하좌우 4방향 탐색
    for(int d=0; d<4; d++){

      int ny = cur_y + dy[d], nx = cur_x + dx[d], new_broken = 0;

      // 다음 좌표가 범위 안에 있고
      if (0<=ny && ny<N && 0<=nx && nx<M) {
        // 다음 칸이 빈 칸(0)이면, 벽을 안 부수고 이동
        if (matrix[ny][nx] == 0) {
          new_broken = cur_broken;
          if (!visited[ny][nx][new_broken]){
            visited[ny][nx][new_broken] = true;
            q.push({ny, nx, new_broken, cur_dist + 1});
          }
        }
        // 다음 칸이 벽(1)이면,
        else {
          // 아직 벽을 부술 여유가 있다면 부수고 이동
          if (cur_broken < K) {
            new_broken = cur_broken + 1;
            if (!visited[ny][nx][new_broken]){
              visited[ny][nx][new_broken] = true;
              q.push({ny, nx, new_broken, cur_dist + 1});
            }
          }
        }
      }
    }
  }
  // 큐가 비었는데 도착하지 못했다면 경로가 존재하지 않음
  return -1;
}

int main(){

  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  // N, M, K 입력 받기
  int N, M, K;
  cin >> N >> M >> K;

  // 맵 정보 입력 받기
  vector<vector<int>> matrix(N, vector<int>(M, 0));

  // 입력이 '0100'과 같이 들어오니까 한 줄씩 string 입력받고 문자를 숫자로 변환
  string line;
  for (int i=0; i<N; i++){
    cin >> line;
    for (int j=0; j<M; j++){
      matrix[i][j] = line[j] - '0';
    }
  }

  // bfs로 벽부수기 조건에서 이동할 수 있는 최단 거리 찾기
  int answer = 0;
  answer = bfs({0, 0, 0, 1}, N, M, K, matrix);
  cout << answer;
}