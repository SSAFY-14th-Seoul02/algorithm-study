/*** 16566. 카드 게임 ***/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int find_set(int x);
void union_set(int a, int b);

int N, M, K;
vector<int> cards;
vector<int> parent;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> K;

    cards.resize(M);
    parent.resize(M + 1);

    for (int i = 0; i < M; i++){
        cin >> cards[i];
        parent[i] = i;
    }
    parent[M] = M;

    sort(cards.begin(), cards.end());

    for (int i = 0; i < K; i++){
        int cheolsu;
        cin >> cheolsu;

        auto it = upper_bound(cards.begin(), cards.end(), cheolsu);
        int idx = distance(cards.begin(), it);

        int real = find_set(idx);

        cout << cards[real] << '\n';
        union_set(real, real + 1);
    }

        return 0;
}

int find_set(int x){
    if(parent[x] == x) return x;
    return parent[x] = find_set(parent[x]);
}

void union_set(int a, int b){
    a = find_set(a);
    b = find_set(b);
    if(a != b) parent[a] = b;
}