/*** 10775. 공항 ***/

#include<iostream>

using namespace std;

int findParent(int x);
void unionParent(int x, int y);

int parent[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int g, p;
	cin >> g >> p;

	for (int i = 1; i <= g; i++) {
		parent[i] = i;
	}

	int count = 0;
	for (int i = 0; i < p; i++) {
		int g;
		cin >> g;

		int availableGate = findParent(g);

		if (availableGate) {
			unionParent(availableGate, availableGate - 1); // 해당 위치의 경로를 이전 위치로 설정
			count++;
		}
		else break; // 경로가 0번 게이트(존재X)로 이어져 도킹할 곳이 없음을 나타냄
	}
		
	cout << count;
	
	return 0;
}

int findParent(int x) {
	if (x == parent[x]) return x;
	return parent[x] = findParent(parent[x]); // 경로 압축
}

void unionParent(int x, int y) {
	x = findParent(x);
	y = findParent(y);

	if (x != y) parent[x] = y;
}