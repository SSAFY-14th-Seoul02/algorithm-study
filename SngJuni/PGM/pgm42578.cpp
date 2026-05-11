#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    
    map<string, int> m;
    for (auto c : clothes) {
        m[c[1]]++;
    }
    
    for (auto i : m) {
        answer *= (i.second + 1);
    }
    
    return answer - 1;
}
