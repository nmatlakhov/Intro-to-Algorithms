#include<vector>
#include<iostream>
using namespace std;

long mod = 1e9 + 7;


long count(vector<vector<int> >& arr, int end, vector<bool>& w, vector<long>& dp)
{
    if (w[end]) { return dp[end]; } 
    else {
        long sum = 0;
        w[end] = true;

        for (auto it = arr[end].begin(); it != arr[end].end(); it++) {
            sum = (sum  + count(arr, *it, w, dp)) % mod;
        }
        dp[end] = sum;
        return sum;
    }

}
long countPaths(vector<vector<int> >& arr, int start, int end)
{
    vector<long> dp(arr.size() + 1, 0);
    vector<bool> w(arr.size() + 1, false);
    w[start] = true;
    dp[start] = 1;
    
    long answer = count(arr, end, w,dp);

    return answer;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, s, d;
    cin >> n >> m;
    vector<vector<int> > arr(n + 1);

    int st, end;
    for (int i = 0; i < m; i++) {
        cin >> st >> end;
        arr[end].push_back(st);
    }
    
    cin >> s >> d;

    cout << countPaths(arr, s,d) << endl;
    return 0;
}