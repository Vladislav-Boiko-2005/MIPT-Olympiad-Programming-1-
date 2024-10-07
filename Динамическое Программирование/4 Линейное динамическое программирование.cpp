#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main() {
		int n;
		cin >> n;
		vector<long long>sost = { 0 };
		string str;
		cin >> str;
		for (auto i : str) { sost.push_back(i - '0'); }
		vector<unsigned long long>dp;
		for (auto i = 0; i < n + 1 + 3; i++) {
			dp.push_back(0);
		}
		if (sost[1] == 0)dp[1] = 1;
		if (sost[2] == 0)dp[2] = 1 + dp[1];
		if (sost[3] == 0)dp[3] = 1 + dp[1] + dp[2];
		for (auto i = 4; i < n + 1; i++) {
			if (sost[i] == 0)dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % (1000000000 + 7);
		}
		cout << dp[n] << '\n';
		return 0;
}
