#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int main() {
	int n,m;
	cin >> n>>m;
	vector<vector<long long>> a (n + 1, vector<long long>(m + 1, 1));
	vector<vector<long long>>dp (n + 1, vector<long long>(m + 1, 0));

	for (auto i = 1; i < n + 1; i++) {
		for (auto j = 1; j < m + 1; j++) {
			int vvod;
			cin >> vvod;
			a[i][j] = vvod;
		}
	}

	dp[0][0] = 1;
	long long limit = pow(10, 9)+9;
	for (auto i = 1; i < n + 1; i++) {
		for (auto j = 1; j < m + 1; j++) {
			if (a[i][j] == 0) {
				dp[i][j] = (dp[i - 1][j] + dp[i][j - 1] + dp[i - 1][j - 1])%limit;
			}
		}
	}
	cout << dp[n][m] << '\n';
}
