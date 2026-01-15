#include <iostream>
#include <string>

using namespace std;

struct Node {
	int id;
	Node* prev;
	Node* next;
};

Node pool[2'000'005];
Node* node_map[1'000'005];
int pool_cnt;

Node* new_node(int id) {
	pool[pool_cnt].id = id;
	pool[pool_cnt].prev = 0;
	pool[pool_cnt].next = 0;

	node_map[id] = &pool[pool_cnt];

	return &pool[pool_cnt++];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N >> M;

	int first_id;
	cin >> first_id;
	Node* head = new_node(first_id);
	Node* prev_node = head;

	for (int i = 1; i < N; i++) {
		int id;
		cin >> id;
		Node* curr = new_node(id);

		prev_node->next = curr;
		curr->prev = prev_node;

		prev_node = curr;
	}

	prev_node->next = head;
	head->prev = prev_node;

	while (M--) {
		string cmd;
		int i, j;
		cin >> cmd;

		if (cmd == "BN") {
			cin >> i >> j;

			Node* curr = node_map[i];
			Node* next = curr->next;

			cout << next->id << "\n";

			Node* new_s = new_node(j);

			curr->next = new_s;
			new_s->prev = curr;

			new_s->next = next;
			next->prev = new_s;
		}
		else if (cmd == "BP") {
			cin >> i >> j;

			Node* curr = node_map[i];
			Node* prev = curr->prev;

			cout << prev->id << "\n";

			Node* new_s = new_node(j);

			prev->next = new_s;
			new_s->prev = prev;

			new_s->next = curr;
			curr->prev = new_s;
		}
		else if (cmd == "CN") {
			cin >> i;

			Node* curr = node_map[i];
			Node* target = curr->next;
			Node* next_of_target = target->next;

			cout << target->id << "\n";

			curr->next = next_of_target;
			next_of_target->prev = curr;
		}
		else if (cmd == "CP") {
			cin >> i;

			Node* curr = node_map[i];
			Node* target = curr->prev;
			Node* prev_of_target = target->prev;

			cout << target->id << "\n";

			prev_of_target->next = curr;
			curr->prev = prev_of_target;
		}
	}
	return 0;
}