#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    
    vector<vector<int>> ip(n, vector<int>(4, 0));

    for (int i = 0; i < n; i++) {
        char dot;
        cin >> ip[i][0] >> dot >> ip[i][1] >> dot >> ip[i][2] >> dot >> ip[i][3];
    }

    vector<int> res_ip(4, 0);
    vector<int> res_mask(4, 0);

    bool flag = false;

    for (int j = 0; j < 4; j++) {
        if (flag) break;

        int val = ip[0][j];
        bool same = true;

        for (int i = 1; i < n; i++) {
            if (ip[i][j] != val) {
                same = false;
                break;
            }
        }

        if (same) {  // 모두 같은 값
            res_ip[j] = val;
            res_mask[j] = 255;
        } else {
            int mn = 255, mx = 0;
            for (int i = 0; i < n; i++) {
                mn = min(mn, ip[i][j]);
                mx = max(mx, ip[i][j]);
            }

            int diff = mn ^ mx;  // 서로 다른 비트를 찾기 위한 XOR

            int mask = 0;
            for (int i = 7; i >= 0; i--) {  // 왼쪽부터 순회하면서 다른 비트 나오면 그 이후 mask는 0
                if (diff & (1 << i)) break;
                mask |= (1 << i);
            }

            res_ip[j] = ip[0][j] & mask;  // 네트워크 주소 = IP & mask
            res_mask[j] = mask;
            flag = true;  // 이후 mask는 모두 0
        }
    }

    cout << res_ip[0] << '.' << res_ip[1] << '.' << res_ip[2] << '.' << res_ip[3] << '\n';
    cout << res_mask[0] << '.' << res_mask[1] << '.' << res_mask[2] << '.' << res_mask[3] << '\n';

    return 0;
}