#include <string>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    map<string, int> total;
    map<string, priority_queue<pair<int, int>>> m;
    
    for (int i = 0; i < genres.size(); i++) {
        total[genres[i]] += plays[i];
        m[genres[i]].push({plays[i], -i});
    }
    
    vector<pair<int, string>> order;
    for (auto i : total) {
        order.push_back({i.second, i.first});
    }
    
    sort(order.rbegin(), order.rend());
    for (int i = 0; i < order.size(); i++) {
        for (int j = 0; !m[order[i].second].empty() && j < 2; j++) {
            answer.push_back(-m[order[i].second].top().second);
            m[order[i].second].pop();
        }
    }
    
    return answer;
}