#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, res = 0;
    cin >> N;

    while (N--) {
        string s;
        cin >> s;

        stack<char> stk;
        for (auto c : s) {
            if (stk.empty()) {
                stk.push(c);
            } else if (stk.top() == c) {
                stk.pop();
            } else {
                stk.push(c);
            }
        }
        
        if (stk.empty()) res++;
    }
    
    cout << res << '\n';

    return 0;
}