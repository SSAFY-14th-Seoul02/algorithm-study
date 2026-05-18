#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Job {
    int request;
    int duration;
    int index;
};

struct comp {
    bool operator()(const Job &a, const Job &b) {
        if (a.duration != b.duration) return a.duration > b.duration;
        if (a.request != b.request) return a.request > b.request;
        return a.index > b.index;
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    
    sort(jobs.begin(), jobs.end());
    
    priority_queue<Job, vector<Job>, comp> pq;
    
    int n = jobs.size();
    int time = 0, idx = 0, cnt = 0;
    
    while (cnt < n) {
        while (idx < n && time >= jobs[idx][0]) {
            pq.push({jobs[idx][0], jobs[idx][1], idx});
            idx++;
        }
        
        if (pq.empty()) {
            time = jobs[idx][0];
            continue;
        }
        
        auto cur = pq.top();
        pq.pop();
        
        time += cur.duration;
        answer += time - cur.request;
        
        cnt++;
    }
    
    return answer / n;
}