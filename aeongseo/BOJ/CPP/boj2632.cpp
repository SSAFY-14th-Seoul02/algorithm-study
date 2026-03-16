/*** 2632. 피자판매 ***/

#include<iostream>

using namespace std;

int countA[2000001], countB[2000001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int od, m, n, A[2002], B[2002];
    int totalA = 0, totalB = 0;

    cin >> od >> m >> n;

    for (int i = 0; i < m; i++){
        cin >> A[i];
        A[i + m] = A[i];
        totalA += A[i];
    }
    for (int i = 0; i < n; i++){
        cin >> B[i];
        B[i + n] = B[i];
        totalB += B[i];
    }

    for (int i = 0; i < m; i++){
        int sum = 0;
        for (int j = 0; j < m - 1; j++){
            sum += A[i + j];
            countA[sum]++;
        }
    }
    countA[totalA]++;
    countA[0] = 1;

    for (int i = 0; i < n; i++){
        int sum = 0;
        for (int j = 0; j < n - 1; j++){
            sum += B[i + j];
            countB[sum]++;
        }
    }
    countB[totalB]++;
    countB[0] = 1;

    long long ans = 0;
    for (int i = 0; i <= od; i++){
        int j = od - i;
        ans += (long long)countA[i] * countB[j];
    }

    cout << ans;

    return 0;
}