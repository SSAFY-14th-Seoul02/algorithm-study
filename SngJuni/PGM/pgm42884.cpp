#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(vector<int> &a, vector<int> &b) {
    return a[1] < b[1];
}

int solution(vector<vector<int>> routes) {
    int answer = 0;
    
    sort(routes.begin(), routes.end(), comp);
    
    int camera = -30001;
    
    for (auto r : routes) {
        if (camera < r[0]) {
            camera = r[1];
            answer++;
        }
    }
    
    return answer;
}