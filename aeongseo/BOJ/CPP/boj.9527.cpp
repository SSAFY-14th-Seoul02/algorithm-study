/*** 9527. 1의 개수 세기 ***/

#include<iostream>
#include<algorithm>

using namespace std;

long long countOnes(long long n);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	long long a, b;
	cin >> a >> b;

	cout << countOnes(b) - countOnes(a - 1);

	return 0;
}

long long countOnes(long long n) {
	if (n < 0) return 0;

	long long count = 0, bit = 1;

	while(bit <= n) {
		long long full_chunks = (n + 1) / (bit * 2);
		count += full_chunks * bit;

		long long remain = (n + 1) % (bit * 2);
		if(remain > bit) count += (remain - bit);

		if (bit > (1LL << 61)) break;
		bit *= 2;
	}

	return count;
}