//#include<map>
//#include<string>
//#include<iostream>
//using namespace std;
//
//int longesUnSubstring(const string& line) {
//	int result = 0, n = line.size();
//	map<char, int> location;
//
//	int left = 0, place_ind;
//	char cur_char;
//
//	for (int right = 0; right < n; right++) {
//		cur_char = line[right];
//		if (location.find(cur_char) != location.end()) {
//			place_ind = location[cur_char] + 1;
//			if (place_ind > left)  left = place_ind;
//		}
//
//		location[cur_char] = right;
//		if (right - left + 1 > result) result = right - left + 1;
//	}
//
//	return result;
//}
//
//int main() {
//	string line;
//	getline(cin, line);
//
//	int result = longesUnSubstring(line);
//	cout << result << endl;
//	return 0;
//}