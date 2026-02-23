/*** 10800. 컬러볼 ***/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct ball{
    int id;
    int color;
    int size;
};

bool compare(const ball& a, const ball& b){
    if(a.size != b.size) return a.size < b.size;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;
    
    vector<ball> balls(N);
    vector<int> color_sum(N+1, 0);
    vector<int> ans(N);

    for (int i = 0; i < N; i++){
        balls[i].id = i;
        cin >> balls[i].color >> balls[i].size;
    }

    sort(balls.begin(), balls.end(), compare);

    int total_sum = 0;
    int j = 0;

    for (int i = 0; i < N; i++){
        while(balls[j].size < balls[i].size){
            total_sum += balls[j].size;
            color_sum[balls[j].color] += balls[j].size;
            j++;
        }

        ans[balls[i].id] = total_sum - color_sum[balls[i].color];
    }

    for (int i = 0; i < N; i++){
        cout << ans[i] << '\n';
    }

    return 0;
}