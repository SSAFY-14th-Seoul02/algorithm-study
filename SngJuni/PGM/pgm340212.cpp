#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int answer = 0;
    
    int l = 1, r = *max_element(diffs.begin(), diffs.end());
    while (l <= r) {
        long long mid = (l + r) / 2;
        long long time = times[0];
        
        
        for (int i = 1; i < diffs.size(); i++) {
            if (mid < diffs[i]) {
                time += (times[i] + times[i - 1]) * (diffs[i] - mid);
            }
            time += times[i];
        }
        
        if (time > limit) {
            l = mid + 1;
        } else {
            answer = mid;
            r = mid - 1;
        }
    }

    return answer;
}