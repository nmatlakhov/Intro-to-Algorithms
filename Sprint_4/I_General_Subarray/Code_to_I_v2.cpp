#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

using int64 = unsigned long long;

vector<int64> GetHashes(vector<int>& data, int64 base, int64 mod) {
	vector<int64> prefixHashes(data.size() + 1, 0);

	for (size_t i = 1; i <= data.size(); i++) {
		prefixHashes[i] =  (prefixHashes[i - 1] * base % mod + 1ULL*data[i - 1]) % mod;
		//cout << prefixHashes[i] << " HASHES " << prefixHashes[i - 1] << endl;
	}

	return prefixHashes;
}

vector<int64> GetPowers(vector<int>& data, int64 base, int64 mod) {
	vector<int64> powers(data.size() + 1, 0);
	powers[0] = 1;

	for (size_t i = 1; i <= data.size(); i++) {
		
		powers[i] = powers[i - 1] * base % mod;
		//cout << powers[i] << " POWERS " << powers[i - 1] << endl;
	}

	return powers;
}

int64 GetHash(vector<int64>& prefixHashes, vector<int64>& powers, int start, int end,int64 mod) {
	int64 temp_minus = prefixHashes[start] * powers[end - start] % mod;
	int64 result = (mod + prefixHashes[end] - temp_minus) % mod;
	//cout << result << " start: " << start << " end: " << end << endl;
	//cout << "pr_end:" << prefixHashes[end] << " pr_start: " << prefixHashes[start] << " power: " << powers[end - start] << endl;
	return result;
}

bool CheckCollision(vector<int64>& lhsVec, vector<int64>& lhsPowers, vector<int64>& rhsVec, vector<int64>& rhsPowers, int window, vector<int>& lhs, vector<int>& rhs) {
	unordered_map<int64, int> hashes;

	for (size_t start = 1; start + window <= lhsVec.size(); start++) {
		hashes.insert({ GetHash(lhsVec, lhsPowers, start - 1, start + window - 1, 1000000007), start  });
	}

	for (size_t start = 1; start + window <= rhsVec.size(); start++) {
		auto it = hashes.find(GetHash(rhsVec, rhsPowers, start-1, start + window-1, 1000000007));

		if (it != hashes.end()) {
			if(lhs[it->second - 1] == rhs[start - 1]) return true;
		}
	}
	return false;
}


int GetLCS(vector<int>& lhsVec, vector<int>& rhsVec) {
	int max_len = 0;
	int left = 1;
	int right = min(lhsVec.size(), rhsVec.size());

	vector<int64> lhsHashes = GetHashes(lhsVec, 257, 1000000007);
	vector<int64> lhsPowers = GetPowers(lhsVec, 257, 1000000007);
	
	vector<int64> rhsHashes = GetHashes(rhsVec, 257, 1000000007);
	vector<int64> rhsPowers = GetPowers(rhsVec, 257, 1000000007);
	

	while (left <= right) {
		int middle = (left + right) / 2;
		//cout << left << " " << right << " " << middle << endl;
		if (CheckCollision(lhsHashes, lhsPowers, rhsHashes, rhsPowers, middle,lhsVec,rhsVec)) {
			max_len = middle;
			left = middle + 1;
		}
		else {
			right = middle - 1;
		}
		
	}

	return max_len;
}

int main() {
	int n, m, max_length = 0, temp_val;
	
	cin >> n;
	vector<int> v1;
	for (int i = 0; i < n; i++) {
		cin >> temp_val;
		v1.push_back(temp_val);
	}
	
	cin >> m;
	vector<int> v2;
	for (int j = 0; j < m; j++) {
		cin >> temp_val;
		v2.push_back(temp_val);
	}
	
	max_length = GetLCS(v1, v2);

	cout << max_length << endl;


	return 0;
}