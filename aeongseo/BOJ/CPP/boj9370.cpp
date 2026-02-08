/*** 9370. 미확인 도착지 ***/

/*
    s -> g -> h -> x 또는 s -> h -> g -> x 중에 s -> x 의 최단거리와 같으면 출력
*/

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

vector<int> dijkstra(int start, int n, vector<vector<pair<int, int>>> graph);

const int INF = 1e9;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    for (int tc = 0; tc < T;tc++) {
        int n, m, t, s, g, h;
        cin >> n >> m >> t >> s >> g >> h;

        vector<vector<pair<int, int>>> graph(n + 1);
        for (int i = 0; i < m; i++)
        {
            int a, b, d;
            cin >> a >> b >> d;
            graph[a].push_back({d, b}); // 양방향 도로 저장
            graph[b].push_back({d, a});
        }

        vector<int> arrival(t); // 목적지 후보 배열
        for (int i = 0; i < t; i++)
        {
            cin >> arrival[i];
        }

        // 각 출발지점 별 최단 거리
        vector<int> dist_s = dijkstra(s, n, graph); // s에서 출발했을 때 거리
        vector<int> dist_g = dijkstra(g, n, graph); // g에서 출발했을 때 거리
        vector<int> dist_h = dijkstra(h, n, graph); // h에서 출발했을 때 거리

        vector<int> result; // 가능한 목적지 배열
        for (int x : arrival)
        {
            long long path_gh = dist_s[g] + dist_g[h] + dist_h[x]; // s -> g -> h -> x
            long long path_hg = dist_s[h] + dist_h[g] + dist_g[x]; // s -> h -> g -> x

            if(path_gh == dist_s[x] || path_hg == dist_s[x]) result.push_back(x);
        }

        sort(result.begin(), result.end());
        for (int i = 0; i < result.size();i++){
            cout << result[i] << ' ';
        }
        cout << '\n';
    }

        return 0;
}

vector<int> dijkstra(int start, int n, vector<vector<pair<int, int>>> graph){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dists(n + 1, INF);
    dists[start] = 0;
    pq.push({0, start});

    while(!pq.empty()){
        auto [d, cur] = pq.top();
        pq.pop();

        if(dists[cur] < d) continue;

        for(auto& edge : graph[cur]){
            int next_d = d + edge.first;
            int next = edge.second;

            if(dists[next] <= next_d) continue;

            dists[next] = next_d;
            pq.push({next_d, next});
        }
    }

    return dists;
}