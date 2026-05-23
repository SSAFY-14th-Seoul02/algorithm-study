#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    
    sort(people.rbegin(), people.rend());
    
    int l = 0, r = people.size() - 1;
    
    while (l <= r) {
        if (people[l] + people[r] <= limit) {
            r--;
        }
        l++;
        answer++;
    }
    
    return answer;
}