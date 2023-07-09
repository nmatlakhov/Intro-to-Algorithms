#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct TrieNode {
	TrieNode* children[26] = { nullptr };
	bool is_terminal = false;
	vector<string> word_set;
};

void add_string(TrieNode* root, string line) {
	TrieNode* current_node = root;
	int n = line.size();

	int id;
	for (int i = 0; i < n; i++) {
		if (islower(line[i])) { continue; }
		id = line[i] - 'A';

		if (current_node->children[id] == nullptr) {
			TrieNode* new_node = new TrieNode;
			current_node->children[id] = new_node;
		}
		current_node = current_node->children[id];
	}

	current_node->is_terminal = true;
	current_node->word_set.push_back(line);


}

void print_all(TrieNode* root, vector<string>& result) {
	if (root->is_terminal) {
		for (auto it = root->word_set.begin(); it != root->word_set.end(); it++) {
			result.push_back(*it);
		}
	}

	for (int i = 0; i < 26; i++) {
		TrieNode* child = root->children[i];
		if (child) {
			print_all(child, result);
		}
	}

}

void find_all(TrieNode* root, string pattern) {
	TrieNode* current_node = root;

	int id, n = pattern.size();
	for (int i = 0; i < n; i++) {
		id = pattern[i] - 'A';
		if (!current_node->children[id]) { 
			cout << "" << endl;
			return; 
		}
		current_node = current_node->children[id];
	}

	vector<string> result;
	print_all(current_node, result);
	sort(result.begin(), result.end());
	for (auto it = result.begin(); it != result.end(); it++) {
		cout << *it << endl;
	}
}

int main() {
	int n;
	string line;
	TrieNode* root = new TrieNode;
	cin >> n >> ws;

	for (int i = 0; i < n; i++) {
		getline(cin, line);
		add_string(root, line);
	}

	int m;
	cin >> m >> ws;

	for (int j = 0; j < m; j++) {
		getline(cin, line);
		find_all(root, line);
	}

	return 0;
}