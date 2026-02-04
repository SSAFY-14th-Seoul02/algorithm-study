/*** 2342. Dance Dance Revolution ***/

/*
    0에서 이동 : 2 -> 현 발 위치가 0
    0 제외에서 인접 이동 : 3 -> 두 위치 차가 1 또는 3
    반대편 이동 : 4 -> 두 위치 차가 2
    같은 지점 : 1 -> 두 위치 동일

    로직
    dp[step][l][r] : 몇번째 왼발 위치 오른발 위치에서의 최소 힘 저장
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

int power(int foot, int t);
int solve(int cnt, int l, int r, int n);

int dp[100001][5][5];
int commands[100001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, cnt = 0;
    while (cin >> t && t != 0){ // 지시사항 모두 저장
        commands[cnt] = t;
        cnt++;
    }

    memset(dp, -1, sizeof(dp)); // 배열 -1로 초기화

    cout << solve(0, 0, 0, cnt);

    return 0;
}

// 이동하는 데 드는 힘 계산
int power(int foot, int t){
    if(foot == 0) return 2;
    else if(foot == t) return 1;
    else if(foot - t == 2 || foot - t == -2) return 4;
    else return 3;
}

// 발이 겹치지 않게 이동했을 떄 최소 힘 계산
int solve(int cnt, int l, int r, int n){
    if (cnt == n) return 0; // 지시사항 끝났으면 0 반환

    if(dp[cnt][l][r] != -1) return dp[cnt][l][r]; // 이미 값이 있으면 그 값 반환

    int command = commands[cnt];

    int move_l = solve(cnt + 1, command, r, n) + power(l, command); // 현재 발 위치에서 왼발 옮겼을 때 힘
    int move_r = solve(cnt + 1, l, command, n) + power(r, command); // 현재 발 위치에서 오른발 옮겼을 떄 힘

    return dp[cnt][l][r] = min(move_l, move_r); // 둘 중 최소값 저장 & 반환
}