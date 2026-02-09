#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, res;
    cin >> s;

    stack<char> op;

    for (char c : s) {
        if (c == '(') {
            op.push(c);
        }
        else if (c == ')') {
            while (!op.empty() && op.top() != '(') {
                res.push_back(op.top());
                op.pop();
            }
            op.pop();  // 여는 괄호 처리
        }
        else if (c == '+' || c == '-') {
            while (!op.empty() && op.top() != '(') {
                res.push_back(op.top());
                op.pop();
            }
            op.push(c);
        }
        else if (c == '*' || c == '/') {
            while (!op.empty() && (op.top() == '*' || op.top() == '/')) {
                res.push_back(op.top());
                op.pop();
            }
            op.push(c);
        } else {
            res.push_back(c);
        }
    }

    while (!op.empty()) {  // 스택에 남은 연산자 처리
        res.push_back(op.top());
        op.pop();
    }

    cout << res << '\n';

    return 0;
}
