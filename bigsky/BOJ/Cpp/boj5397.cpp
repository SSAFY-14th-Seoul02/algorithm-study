#include <iostream>
#include <string>

using namespace std;

struct Node {
	char val;
	Node* prev;
	Node* next;
};

Node pool[1'000'005];
int pool_cnt;

Node* head;
Node* tail;
Node* cursor;


Node* new_node(char val) {
	pool[pool_cnt].val = val;
	pool[pool_cnt].prev = 0;
	pool[pool_cnt].next = 0;
	return &pool[pool_cnt++];
}

void init() {
	pool_cnt = 0;

	head = new_node(0);
	tail = new_node(0);

	head->next = tail;
	tail->prev = head;

	cursor = tail;
}

void insert(char c) {
	Node* add = new_node(c);

	Node* right_node = cursor;
	Node* left_node = cursor->prev;

	add->prev = left_node;
	add->next = right_node;

	left_node->next = add;
	right_node->prev = add;
}

void erase() {
	if (cursor->prev == head) return;

	Node* remove = cursor->prev;
	
	Node* right_node = cursor;
	Node* left_node = remove->prev;

	left_node->next = right_node;
	right_node->prev = left_node;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	for (int tc = 0; tc < T; tc++) {
		init();

		string s;
		cin >> s;

		for (char cmd : s) {
			switch (cmd) {
			case '<':
				if (cursor->prev != head) {
					cursor = cursor->prev;
				}
				break;

			case '>':
				if (cursor != tail) {
					cursor = cursor->next;
				}
				break;

			case '-':
				erase();
				break;

			default:
				insert(cmd);
				break;
			}
		}

		Node* curr = head->next;
		while (curr != tail) {
			cout << curr->val;
			curr = curr->next;
		}

		cout << "\n";
	}
}