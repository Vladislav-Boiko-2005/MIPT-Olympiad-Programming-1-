
#include <iostream>
#include <vector>
#include<utility>
#include<cmath>
using namespace std;

vector<vector<int>>dp;
long long limit = pow(10, 9) + 123;

void obhod(int n, int m) {
	for (auto i = 1; i <= m; i++) {
		pair <int,int> elem=make_pair(1,i);
		while (elem.second != 0 ) {
			if (elem.first <= n and elem.second <= m) {
				dp[elem.first - 1][elem.second + 2] += dp[elem.first][elem.second];
				dp[elem.first - 1][elem.second + 2] %= limit;
				dp[elem.first + 1][elem.second + 2] += dp[elem.first][elem.second];
				dp[elem.first + 1][elem.second + 2] %= limit;
				dp[elem.first + 2][elem.second - 1] += dp[elem.first][elem.second];
				dp[elem.first + 2][elem.second - 1] %= limit;
				dp[elem.first + 2][elem.second + 1] += dp[elem.first][elem.second];
				dp[elem.first + 2][elem.second + 1] %= limit;
			}
			elem.first += 1;
			elem.second -= 1;
		}
	}
	for (auto i = 2; i <= n; i++) {
		pair<int, int> elem = make_pair(i, m);
		while (elem.second != 0) {
			if (elem.first <= n and elem.second <= m) {
				dp[elem.first - 1][elem.second + 2] += dp[elem.first][elem.second];
				dp[elem.first - 1][elem.second + 2] %= limit;
				dp[elem.first + 1][elem.second + 2] += dp[elem.first][elem.second];
				dp[elem.first + 1][elem.second + 2] %= limit;
				dp[elem.first + 2][elem.second - 1] += dp[elem.first][elem.second];
				dp[elem.first + 2][elem.second - 1] %= limit;
				dp[elem.first + 2][elem.second + 1] += dp[elem.first][elem.second];
				dp[elem.first + 2][elem.second + 1] %= limit;
			}
			elem.first += 1;
			elem.second -= 1;
		}
	}
}

int main() {
	int n,m;
	cin >> n >>m;

	for (auto i = 0; i <= n + 4; i++) {
		dp.push_back({});
		for (auto j = 0; j <= m + 4; j++) {
			dp[i].push_back(0);
		}
	}
	dp[1][1] = 1;
	obhod(n, m);
	cout << dp[n][m] << '\n';
    return 0;
}

