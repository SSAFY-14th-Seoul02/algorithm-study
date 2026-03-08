/*** 7453. 합이 0인 네 정수 ***/

#include<iostream>
#include<algorithm>

using namespace std;

int A[4000], B[4000], C[4000], D[4000];
int AB[16000000], CD[16000000];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++){
        cin >> A[i] >> B[i] >> C[i] >> D[i];
    }

    int idx = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            AB[idx] = A[i] + B[j];
            CD[idx] = C[i] + D[j];
            idx++;
        }
    }

    sort(AB, AB + idx);
    sort(CD, CD + idx);

    int left = 0, right = idx - 1;
    long long cnt = 0;

    while(left < idx && right >= 0){
        int cur = AB[left] + CD[right];

        if(cur == 0){
            long long curAB = AB[left], curCD = CD[right];
            long long cntAB = 0, cntCD = 0;

            while(left < idx && AB[left] == curAB){
                cntAB++;
                left++;
            }

            while(right >= 0 && CD[right] == curCD){
                cntCD++;
                right--;
            }

            cnt += cntAB * cntCD;
        }
        else if(cur < 0) left++;
        else right--;
    }

    cout << cnt;

    return 0;
}