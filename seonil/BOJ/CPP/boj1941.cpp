/*
BOJ1941. 소문난 칠공주

[문제]
총 25명의 여학생들로 이루어진 여학생반은 5×5의 정사각형 격자 형태로 자리가 배치되었고, 얼마 지나지 않아 이다솜과 임도연이라는 두 학생이 두각을 나타내며 다른 학생들을 휘어잡기 시작했다.
곧 모든 여학생이 ‘이다솜파’와 ‘임도연파’의 두 파로 갈라지게 되었으며, 얼마 지나지 않아 ‘임도연파’가 세력을 확장시키며 ‘이다솜파’를 위협하기 시작했다.
위기의식을 느낀 ‘이다솜파’의 학생들은 과감히 현재의 체제를 포기하고, ‘소문난 칠공주’를 결성하는 것이 유일한 생존 수단임을 깨달았다. ‘소문난 칠공주’는 다음과 같은 규칙을 만족해야 한다.

1. 이름이 이름인 만큼, 7명의 여학생들로 구성되어야 한다.
2. 강한 결속력을 위해, 7명의 자리는 서로 가로나 세로로 반드시 인접해 있어야 한다.
3. 화합과 번영을 위해, 반드시 ‘이다솜파’의 학생들로만 구성될 필요는 없다.
4. 그러나 생존을 위해, ‘이다솜파’가 반드시 우위를 점해야 한다. 따라서 7명의 학생 중 ‘이다솜파’의 학생이 적어도 4명 이상은 반드시 포함되어 있어야 한다.
여학생반의 자리 배치도가 주어졌을 때, ‘소문난 칠공주’를 결성할 수 있는 모든 경우의 수를 구하는 프로그램을 작성하시오.

[입력]
'S'(이다‘솜’파의 학생을 나타냄) 또는 'Y'(임도‘연’파의 학생을 나타냄)을 값으로 갖는 5*5 행렬이 공백 없이 첫째 줄부터 다섯 줄에 걸쳐 주어진다.

[출력]
첫째 줄에 ‘소문난 칠공주’를 결성할 수 있는 모든 경우의 수를 출력한다.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

// 상하좌우 델타 배열
  int dy[] = {-1, 1, 0, 0};
  int dx[] = {0, 0, -1, 1};

// 선택된 것들 중 S가 4개 이상인지 확인하는 함수
bool hasFourOrMoreS(vector<pair<int,int>>& selected, vector<vector<char>>& matrix){
  int cnt = 0;
  for (auto [y, x] : selected){
    if (matrix[y][x] == 'S') cnt++;
  }
  return cnt >= 4;
}

// 선택된 것들이 모두 인접해 있는지 확인하는 함수
int bfs(pair<int, int> start, int mask){

  // BFS 준비
  bool visited[5][5] = {false};
  queue<pair<int, int>> q;
  q.push(start);
  auto [sy, sx] = start;
  visited[sy][sx] = true;
  int count = 1;

  // BFS
  while(!q.empty()){
    auto [cur_y, cur_x] = q.front();
    q.pop();

    // 이웃한 4방향 칸 순회
    for(int d=0; d<4; d++){
      int ny = cur_y + dy[d], nx = cur_x + dx[d];
      if (0 <= ny && ny < 5 && 0<= nx && nx < 5){
        // 다음 칸이 방문 안한 칸이고, 다음 칸에 대응되는 비트마스크가 선택된 칸이라면 큐에 추가
        if(!visited[ny][nx] && (mask & (1 << (ny * 5 + nx)))){
          visited[ny][nx] = true;
          q.push({ny, nx});
          count += 1;
        }
      }
    }
  }
  return count;
}

int main() {

  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  // 행렬 입력 받기
  vector<vector<char>> matrix(5, vector<char>(5, 0));
  string line;
  for(int i=0; i<5; i++){
    cin >> line;
    for(int j=0; j<5; j++){
      matrix[i][j] = line[j];
    }
  }

  int answer = 0;

  // 비트마스크 활용하여 25칸 중 7칸 뽑기
  // __builtin_popcount(mask): mask의 2진수 표현에서 1인 비트의 개수를 세는 함수
  for (int mask=0; mask<(1LL<<25); mask++){
    if (__builtin_popcount(mask) != 7){
      continue;
    }

    // 비트 위치 뽑기
    vector<pair<int, int>> selected;
    // 25자리 순회하면서 켜진 비트의 위치에 해당하는 좌표를 selected에 뽑기
    for (int k=0; k<25; k++){
      if (mask & (1 << k)){
        selected.push_back({k / 5, k % 5});
      }
    }

    // selected에 4개 이상의 'S'가 있고, 동시에 BFS 연결성 검사를 통과한다면 경우의 수 count
    if (hasFourOrMoreS(selected, matrix) && bfs(selected[0], mask) == 7){
      answer++;
    }
  }
  // 결과 출력
  cout << answer << endl;
  return 0;
}