#include<iostream>
#include<vector>
using namespace std;

int Min(int v1, int v2, int v3) {
	if (v1 > v2) { v1 = v2; }
	if (v1 > v3) { v1 = v3; }
	return v1;
}

int main() {
	int n, m;
	cin >> m >> n;
	vector<vector<int>>a;
	vector<vector<int>>dp;
	for (auto i = 0; i < m; i++) {
		a.push_back({});
		dp.push_back({});
		for (auto j = 0; j < n; j++) {
			a[i].push_back(0);
			dp[i].push_back(0);
		}
	}
	for (auto i = 0; i < m ; i++) {
		for (auto j = 0; j < n; j++) {
			int vvod;
			cin >> vvod;
			a[i][j] = vvod;
		}
	}
	dp[0][0] = a[0][0];
	for (auto i = 1; i < n; i++) { dp[0][i] = dp[0][i - 1] + a[0][i]; }
	for (auto i = 1; i < m; i++) { dp[i][0] = dp[i-1][0] + a[i][0]; }
	for (auto i = 1; i < m; i++) {
		for (auto j = 1; j < n; j++) {
			dp[i][j] = Min(dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]) + a[i][j];
		}
	}
	cout << dp[m-1][n-1];
}
