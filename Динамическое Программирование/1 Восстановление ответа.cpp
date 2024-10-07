#include<iostream>
#include<vector>
#include<utility>
#include<cmath>
using namespace std;

vector<vector<int>>a;
vector<vector<int>>dp;
int infinity = pow(10, 5);


int Min(int v1, int v2, int v3) {
	if (v1 > v2)v1 = v2;
	if (v1 > v3)v1 = v3;
	return v1;
}


int main() {
	int n, m;
	cin >> n >> m;
	for (auto i = 0; i <= n+1; i++) {
		a.push_back({});
		dp.push_back({});
		for (auto j = 0; j <= m+1; j++) {
			a[i].push_back(0);
			dp[i].push_back(infinity);
		}
	}
	
	for (auto i = 1; i <= n; i++) {
		for (auto j = 1; j <= m; j++) {
			int vvod;
			cin >> vvod;
			a[i][j]=vvod;
		}
	}
	dp[0][0] = 0;

	for (auto i = 1; i <= n; i++) {
		for (auto j = 1; j <= m; j++) {
			dp[i][j] = Min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + a[i][j];
		}
	}
	int x = m;
	int y = n;
	vector<pair<int, int>>itog;
	while ((y != 1) || (x != 1)) {
		itog.push_back(make_pair(y, x));
		if (dp[y][x] == a[y][x] + dp[y - 1][x]) {
			y -= 1;
		}
		else if(dp[y][x]==a[y][x]+dp[y][x-1]) {
			x -= 1;
		}
		else {
			y -= 1;
			x -= 1;
		}
	}
	itog.push_back(make_pair(y, x));
	cout << dp[n][m] << ' ' << itog.size()<<'\n';
	for (int i = itog.size() - 1; i >= 0;i--) {
		cout << itog[i].first << ' ' << itog[i].second << '\n';
	}
}

