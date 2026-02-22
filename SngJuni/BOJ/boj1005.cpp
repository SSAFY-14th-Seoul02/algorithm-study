#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, k, w;
        vector<int> d(1001, 0);       // 각 건물의 건설 시간
        vector<int> degree(1001, 0);  // 진입 차수(선행 건물 갯수)
        vector<int> sum(1001, 0);     // 해당 건물까지 걸리는 최소 시간
        vector<int> arr[1001];        // 건설 순서 그래프
        queue<int> q;
        
        cin >> n >> k;

        // 건설 시간 입력
        for (int i = 1; i <= n; i++) {
            cin >> d[i];
            sum[i] = d[i];
        }

        // 건설 순서 입력
        for (int i = 0; i < k; i++) {
            int x, y;
            cin >> x >> y;

            arr[x].push_back(y);
            degree[y]++;
        }

        cin >> w;
        
        // 진입 차수가 0인 건물부터 시작
        for (int i = 1; i <= n; i++) {
            if (degree[i] == 0) q.push(i);
        }
        
        // 위상정렬
        while (!q.empty()) {
            int now = q.front();
            q.pop();
            
            // now를 선행으로 가지는 다음 건물들 처리
            for (int i = 0; i < arr[now].size(); i++) {
                int next = arr[now][i];

                // next를 짓는데 걸리는 시간 = (now까지 걸린 시간 + next 건설 시간) 중 최댓값
                if (sum[now] + d[next] > sum[next]) sum[next] = sum[now] + d[next];

                // 진입 차수 감소
                degree[next]--;

                // 모든 선행 조건이 끝난 경우
                if (degree[next] == 0) q.push(next);
            }
        }
        
        cout << sum[w] << '\n';
    }
    
    return 0;
}