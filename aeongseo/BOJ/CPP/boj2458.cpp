/*** 2458. 키 순서 ***/

#include<iostream>
#include<vector>

using namespace std;

vector<vector<bool>> connected;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    connected.assign(N + 1, vector<bool>(N + 1, false));

    for (int i = 0; i < M; i++){
        int u, v;
        cin >> u >> v;
        connected[u][v] = true;
    }

    for (int k = 1; k <= N; k++){
        for (int i = 1; i <= N; i++){
            for (int j = 1; j <= N; j++){
                if(connected[i][k] && connected[k][j]) connected[i][j] = true;
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= N; i++){
        int cnt = 0;
        for (int j = 1; j <= N; j++){
            if(connected[i][j] || connected[j][i]) cnt++;
        }

        if(cnt == N - 1) ans++;
    }

    cout << ans;

    return 0;
}