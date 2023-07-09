#include<string>
#include<vector>
#include<iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	string line,temp, result = "";
	getline(cin, line);

	size_t lin_siz = line.size();
	vector<string> pos_vec(lin_siz + 1, "");

	int n, temp_value;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> temp >> temp_value;
		pos_vec[temp_value] = temp;
	}

	for (int j = 0; j < lin_siz; j++) {
		if (pos_vec[j] == "") {
			result +=  line[j];
		}
		else {
			result +=  pos_vec[j] + line[j];
		}
	}
	if (pos_vec[lin_siz] != "") { result += pos_vec[lin_siz]; }

	cout << result << endl;

	return 0;
}