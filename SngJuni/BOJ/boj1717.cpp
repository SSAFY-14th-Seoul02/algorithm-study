#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int n, m;
vector<int> parent;

int find_set(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find_set(parent[x]);  // 경로 압축
}

void union_set(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) parent[b] = a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    parent.assign(n + 1, 0);
    iota(parent.begin(), parent.end(), 0);

    for (int i = 0; i < m; i++) {
        int op, a, b;
        cin >> op >> a >> b;

        if (op == 0) {
            union_set(a, b); 
        } else {
            if (find_set(a) == find_set(b)) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }

    return 0;
}
