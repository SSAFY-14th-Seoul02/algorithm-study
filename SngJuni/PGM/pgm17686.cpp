#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct File {
    string origin;
    string head;
    int num;
};

bool comp(const File &a, const File &b) {
    if (a.head != b.head) return a.head < b.head;
    else return a.num < b.num;
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    
    vector<File> arr;
    for (auto s : files) {
        string origin = s;
        string head = "", num = "";
        
        int idx = 0;
        while (!isdigit(s[idx])) {
            head += tolower(s[idx]);
            idx++;
        }
        while (isdigit(s[idx])) {
            num += s[idx];
            idx++;
        }
        
        File f;
        f.origin = origin;
        f.head = head;
        f.num = stoi(num);
        
        arr.push_back(f);
    }
    
    stable_sort(arr.begin(), arr.end(), comp);
    
    for (auto i : arr) {
        answer.push_back(i.origin);
    }
    
    return answer;
}
