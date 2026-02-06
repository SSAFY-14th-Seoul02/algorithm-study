/*
BOJ1038 : 감소하는 수 (G5)

해결 방법 : 
시도 1 : 개수를 찾고, 숫자를 찾는 방식으로 하려고 했는데, 구현은 됐으나, 원하는 숫자가 안 나옴
시도 2 : 숫자를 미리 만들고, sort해서 인덱스로 찾는 방식으로 진행 -> int가 부족해서 틀렸습니다
시도 3 : int 대신 long long으로 작성
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> arr;

void find_num(long long num) {
    arr.push_back(num);
    int last_digit = num % 10;
    for (int i = 0; i < last_digit; i++) {
        long long next_num = num * 10 + i;
        find_num(next_num);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    for (int i = 0; i < 10; i++) {
        find_num(i);
    }
    sort(arr.begin(), arr.end());

    if (n >= arr.size()) {
        cout << -1 << "\n";
    } else {
        cout << arr[n] << "\n";
    }

    return 0;
}