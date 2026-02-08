/*** 2243. 사탕상자 ***/

/*
	세그먼트 트리
	- 여러 개의 데이터가 연속적으로 존재할 때, 특정 구간의 합(or 최대최소)을 구하거나 데이터 업데이트를 빠르게 수행
	- 완전 이진 트리
		- 리프 노드 : 배열의 각 실제 요소 저장(사탕의 맛별 개수)
		- 부모 노드 : 자식 노드들의 합 저장
	- O(log N)
*/

#include<iostream>
#include<vector>

using namespace std;

int find_candy(int node, int start, int end, int k);
void insert_candy(int node, int start, int end, int target, int diff);

const int MAX = 1000000;
long long candy[MAX * 4];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	while (n--) {
		int a, b, c;
		cin >> a;
		if (a == 1) { // 사탕 꺼내는 경우
			cin >> b;
			int ans = find_candy(1, 1, MAX, b); // 사탕 찾기
			cout << ans << '\n';
			insert_candy(1, 1, MAX, ans, -1); // 하나 꺼냈으므로 개수 줄이기
		}
		else { // 사탕 넣는 경우
			cin >> b >> c;
			insert_candy(1, 1, MAX, b, c); // 사탕 추가
		}
	}

	return 0;
}

int find_candy(int node, int start, int end, int k) {
	if (start == end) return start; // start와 end가 같으면 그게 찾는 사탕

	int mid = (start + end) / 2;

	if (candy[node * 2] >= k) { // 왼쪽에 담긴 사탕 개수가 k개 이상일 때
		return find_candy(node * 2, start, mid, k); // 왼쪽 구간에서 사탕 찾기
	}
	else { // 왼쪽에 담긴 사탕 개수가 k개 미만일 때
		return find_candy(node * 2 + 1, mid + 1, end, k - candy[node * 2]); // 왼쪽 사탕 개수만큼 건너뛰었으므로 k에서 빼줌
	}
}

void insert_candy(int node, int start, int end, int target, int diff) {
	if (target < start || target > end) return; // candy 배열에 해당하는 맛이 없다면 종료

	candy[node] += diff; // 현재 노드의 사탕 개수를 더함
	if (start != end) { // 리프노드가 아닐 때만 자식 노드로 업데이트
		int mid = (start + end) / 2;
		insert_candy(node * 2, start, mid, target, diff); // 왼쪽 자식
		insert_candy(node * 2 + 1, mid + 1, end, target, diff); // 오른쪽 자식
	}
}