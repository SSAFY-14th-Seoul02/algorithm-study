/*** 13334. 철로 ***/

#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

struct Line {
    int start;
    int end;
};

bool compare(const Line& a, const Line& b){
    if(a.end == b.end) return a.start < b.start;
    return a.end < b.end;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<Line> lines;
    for (int i = 0; i < n; i++){
        int h, o;
        cin >> h >> o;
        if (h > o) swap(h, o);
        lines.push_back({h, o});
    }

    int d;
    cin >> d;

    sort(lines.begin(), lines.end(), compare); // 끝점 기준 정렬

    priority_queue<int, vector<int>, greater<int>> pq; // 시작점 저장
    int max_cnt = 0;

    for (int i = 0; i < n; i++){
        int curs = lines[i].start;
        int cure = lines[i].end;

        if(cure - curs <= d){
            pq.push(curs);

            int rail_lim = cure - d;

            while(!pq.empty() && pq.top() < rail_lim) {
                pq.pop();
            }

            max_cnt = max(max_cnt, (int)pq.size());
        }
    }

    cout << max_cnt;

    return 0;
}