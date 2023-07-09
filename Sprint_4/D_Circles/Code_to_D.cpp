#include<string>
#include<iostream>
#include<queue>
#include<unordered_map>
#include<sstream>
using namespace std;


int main() {
	int n; 
	string temp_val;

	unordered_map<string,int> hobbie_group;
	queue<string> group_order;

	getline(cin, temp_val);
	istringstream iss(temp_val);
	iss >> n;

	for (int i = 0; i < n; i++) {
		getline(cin, temp_val);
		if(hobbie_group.find(temp_val) == hobbie_group.end()){
			hobbie_group.insert({ temp_val,1 });
			group_order.push(temp_val);
		}
	}

	while (!group_order.empty()) {
		cout << group_order.front() << endl;
		group_order.pop();
	}
	
	return 0;
}