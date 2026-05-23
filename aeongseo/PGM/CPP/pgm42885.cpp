/***  구명보트 (L2) ***/

#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    vector<bool> used(people.size(), false);
    
    sort(people.begin(), people.end());
    
    int i = 0, j = people.size() - 1;
    
    while(i <= j){
        if(people[i] + people[j] <= limit) i++;
        
        j--;
        answer++;
    }

    return answer;
}