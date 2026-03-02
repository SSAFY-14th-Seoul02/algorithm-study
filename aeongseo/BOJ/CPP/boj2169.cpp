/*** 2169. 로봇 조종하기 ***/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int INF = 1e9;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> mars(1001, vector<int>(1001, 0)), dp(1002, vector<int>(1002, -INF));

    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= M; j++){
            cin >> mars[i][j];
        }
    }

    dp[1][1] = mars[1][1];
    for(int j=2; j<=M; j++){
        dp[1][j] = dp[1][j - 1] + mars[1][j];
    }

    for (int i = 2; i <= N; i++){
        vector<int> ltr(1002, -INF), rtl(1002, -INF);
        ltr[1] = dp[i-1][1] + mars[i][1];
        rtl[M] = dp[i-1][M] + mars[i][M];
        
        for (int j = 2; j <= M; j++){
            ltr[j] = max(dp[i - 1][j], ltr[j - 1]) + mars[i][j];
            rtl[M + 1 - j] = max(dp[i - 1][M + 1 - j], rtl[M + 2 - j]) + mars[i][M + 1 - j];
        }
        for (int j = 1; j <= M; j++){
            dp[i][j] = max(ltr[j], rtl[j]);
        }
    }

    cout << dp[N][M];

    return 0;
}