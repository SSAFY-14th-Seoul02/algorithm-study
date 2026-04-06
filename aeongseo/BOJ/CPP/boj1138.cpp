/*** 1138. 한 줄로 서기 ***/

// 0이면 맨앞부터 빈칸에 넣기
// x면 맨앞부터 빈칸+x칸에 넣기

#include<iostream>
#include<vector>

using namespace std;

vector<int> person, height;
vector<bool> used;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    person.resize(N);
    height.resize(N);
    used.assign(N, false);

    for (int i = 0; i < N; i++){
        cin >> person[i];
    }

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){ // height index
            if(used[j]) continue; // 누가 이미 서있으면 continue

            int cnt = person[i];
            int k = j;
            while(cnt > 0){
                if(!used[k + 1]) cnt--;
                k++;
            }

            used[k] = true;
            height[k] = i + 1;
            break;
        }
    }

    for (int i = 0; i < N; i++){
        cout << height[i] << ' ';
    }

        return 0;
}