#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    stack<int> stk;
    long long res;

    for (int i = 0; i < N; i++) {
        int h;
        cin >> h;

        while (!stk.empty() && stk.top() <= h) {
            stk.pop();
        }

        res += stk.size();

        stk.push(h);
    }

    cout << res << '\n';

    return 0;
}