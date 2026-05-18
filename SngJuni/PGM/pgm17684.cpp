#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    
    map<string, int> m;
    for (int i = 0; i < 26; i++) {
        string s = "";
        s += char('A' + i);
        m[s] = i + 1;
    }
    
    int n = msg.size();
    int idx = 0;
    int ln = 27;
    
    while (idx < n) {
        string w = "";
        w += msg[idx];

        int next = idx + 1;

        while (next < n) {
            string temp = w + msg[next];

            if (m.count(temp)) {
                w = temp;
                next++;
            } else {
                break;
            }
        }
        
        answer.push_back(m[w]);
        
        if (next < msg.size()) {
            string nw = w + msg[next];
            m[nw] = ln++;
        }

        idx = next;
    }
    
    return answer;
}