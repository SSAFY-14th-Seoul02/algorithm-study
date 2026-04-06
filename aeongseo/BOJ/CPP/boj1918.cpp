/*** 1918. 후위 표기식 ***/

#include <iostream>
#include <string>
#include <stack>

using namespace std;

// 연산자 우선순위
int priority(char op){
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0; // '('의 경우
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string expr;
    cin >> expr;

    stack<char> s;
    string result = "";

    for(char c : expr){
        if (isalpha(c)) result += c; // 피연산자(알파벳)은 결과에 바로 추가
        else if (c == '(') s.push(c); // '('는 무조건 스택에 push
        else if (c == ')') { // ')'를 만나면 '('가 나올 때까지 스택 pop하여 결과에 추가
            while(!s.empty() && s.top() != '('){
                result += s.top();
                s.pop();
            }
            s.pop(); // '('를 스택에서 제거
        }
        else{ // 현재 연산자보다 우선순위 같거나 높은 연산자를 pop하여 결과에 추가
            while (!s.empty() && priority(s.top()) >= priority(c)) {
                result += s.top();
                s.pop();
            }
            s.push(c); // 우선순위 낮거나 빈 스택 만나면 현재 연산자 push
        }

    }
    
    // 스택에 연산자 남아있으면 결과에 추가
    while(!s.empty()){
        result += s.top();
        s.pop();
    }

        cout << result;
        
    return 0;
}