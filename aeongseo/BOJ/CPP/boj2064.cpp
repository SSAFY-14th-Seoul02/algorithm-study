/*** 2064. IP 주소 ***/

/*
	네트워크 마스크 : 공통된 비트 부분은 1, 그 이후는 0으로 표현
	네트워크 주소 : 해당 네트워크의 시작점. 마스크와 & 연산
*/

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	scanf("%d", &n);

	vector<unsigned int> ips(n);

	// ip 주소를 32비트 이진수로 합쳐서 저장
	for (int i = 0; i < n; i++) {
		unsigned int a, b, c, d;
		scanf("%u.%u.%u.%u", &a, &b, &c, &d);
		ips[i] = (a << 24) | (b << 16) | (c << 8) | d;
	}

	// 각 ip 주소들의 공통점을 xor로 연산 -> 1 : 다름, 0 : 같음
	int diff = 0;
	for (int i = 1; i < n; i++) {
		diff |= (ips[0] ^ ips[i]);
	}

	// 어디까지 같은 주소인지 찾기
	int m = 32; // 같은 주소의 비트 수
	for (int i = 31; i >= 0; i--) {
		if ((diff >> i) & 1) {
			m = 31 - i;
			break;
		}
	}


	unsigned int net_mask = 0;
	if (m > 0) net_mask = (0xFFFFFFFF << (32 - m)) & 0xFFFFFFFF; // m=0일 때 모두 비트를 밀어버리면 오류 발생함
	unsigned int net_addr = ips[0] & net_mask;


	// 십진수로 변환하여 출력
	printf("%u.%u.%u.%u\n", (net_addr >> 24) & 0xFF, (net_addr >> 16) & 0xFF, (net_addr >> 8) & 0xFF, net_addr & 0xFF);
	printf("%u.%u.%u.%u\n", (net_mask >> 24) & 0xFF, (net_mask >> 16) & 0xFF, (net_mask >> 8) & 0xFF, net_mask & 0xFF);

	return 0;
}