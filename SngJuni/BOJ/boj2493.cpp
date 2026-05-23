#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    stack<pair<int, int>> stk;
    vector<int> res(N);

    for (int i = 0; i < N; i++) {
        int h;
        cin >> h;

        while (!stk.empty() && stk.top().first < h) {
            stk.pop();
        }

        if (stk.empty()) {
            res[i] = 0;
        } else {
            res[i] = stk.top().second;
        }

        stk.emplace(h, i + 1);
    }

    for (auto i : res) {
        cout << i << ' ';
    }

    return 0;
}