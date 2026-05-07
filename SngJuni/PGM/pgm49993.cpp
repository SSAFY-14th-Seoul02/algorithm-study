#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    
    map<char, int> m;
    for (int i = 0; i < skill.size(); i++) {
        m[skill[i]] = i;
    }
    
    for (auto s : skill_trees) {
        int temp = 0;
        bool flag = true;
        
        for (auto c : s) {
            if (m.find(c) != m.end()) {
                if (m[c] != temp) {
                    flag = false;
                    break;
                } else {
                    temp++;
                }
            }
        }
        if (flag) answer++;
    }
    
    return answer;
}