#include <iostream>
#include <string>

using namespace std;

struct Node {
	char val;
	Node* prev;
	Node* next;
};

Node pool[600005];
int pool_cnt;

Node* new_node(char val) {
	pool[pool_cnt].val = val;
	pool[pool_cnt].prev = nullptr;
	pool[pool_cnt].next = nullptr;
	return &pool[pool_cnt++];
}

Node* head;
Node* tail;
Node* cursor;

void init() {
	pool_cnt = 0;
	head = new_node(0);
	tail = new_node(0);

	head->next = tail;
	tail->prev = head;

	cursor = tail;
}

void insert(char val) {
	Node* add = new_node(val);

	Node* right_node = cursor;
	Node* left_node = cursor->prev;

	add->prev = left_node;
	add->next = right_node;

	left_node->next = add;
	right_node->prev = add;
}

void erase() {
	if (cursor->prev == head) return;

	Node* delete_node = cursor->prev;
	Node* left_node = delete_node->prev;
	Node* right_node = cursor;

	left_node->next = right_node;
	right_node->prev = left_node;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	init();

	string s;
	cin >> s;

	for (char c : s) {
		insert(c);
	}

	int m;
	cin >> m;

	for (int i = 0; i < m; i++) {
		char cmd;
		cin >> cmd;

		if (cmd == 'L') {
			if (cursor->prev != head) {
				cursor = cursor->prev;
			}
		}
		else if (cmd == 'D') {
			if (cursor != tail) {
				cursor = cursor->next;
			}
		}
		else if (cmd == 'B') {
			erase();
		}
		else if (cmd == 'P') {
			char c;
			cin >> c;
			insert(c);
		}
	}

	Node* curr = head->next;
	while (curr != tail) {
		cout << curr->val;
		curr = curr->next;
	}

	return 0;
}