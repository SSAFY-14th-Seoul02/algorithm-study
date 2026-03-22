/*** 9576. 책 나눠주기 ***/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct Request{
    int a, b;
};

bool compare(const Request& s, const Request& e){
    if(s.b != e.b) return s.b < e.b;
    return s.a < e.a;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    for (int tc = 0; tc < T; tc++){
        int n, m;
        cin >> n >> m;
    
        vector<Request> student(m);
        for (int i = 0; i < m; i++){
            cin >> student[i].a >> student[i].b;
        }
    
        sort(student.begin(), student.end(), compare);
    
        vector<bool> taken(n + 1, false);
        int cnt = 0;
    
        for (int i = 0; i < m; i++){
            for (int j = student[i].a; j <= student[i].b; j++){
                if(!taken[j]){
                    taken[j] = true;
                    cnt++;
                    break;
                }
            }
        }

        cout << cnt << '\n';
    }

    return 0;
}