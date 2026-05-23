#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    for (int i = 1; i <= yellow; i++) {
        if (yellow % i != 0) continue;
        
        int w = yellow / i;
        
        int border = (w + 2) * (i + 2) - yellow;
        if (border == brown) {
            answer.push_back(w + 2);
            answer.push_back(i + 2);
            break;
        }
    }
    
    return answer;
}