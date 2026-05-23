#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
        
    sort(times.begin(), times.end());
    
    long long l = 1, r = (long long)times.back() * n;
    
    while (l <= r) {
        long long mid = (l + r) / 2;
        
        long long cnt = 0;
        for (auto t : times) {
            cnt += mid / t;
            
            if (cnt >= n) break;
        }
        
        if (cnt >= n) {
            answer = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    
    return answer;
}
