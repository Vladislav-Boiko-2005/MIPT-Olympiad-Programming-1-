#include<iostream>
#include<vector>
using namespace std;


long long Max(long long v1, long long v2, long long v3) {
	if (v1 < v2)v1 = v2;
	if (v1 < v3)v1 = v3;
	return v1;
}

long long Max(long long v1, long long v2) {
	if (v1 < v2)v1 = v2;
	return v1;
}


int main() {
	int n;
	cin >> n;
	vector<long long>a(n + 1 + 5, 0);
	vector<long long>dp(n + 1 + 5, 0);
	for (auto i = 1; i <= n; i++) {
		long long vvod;
		cin >> vvod;
		a[i] = vvod;
	}
	dp[0] = 0;
	dp[1] = dp[0] + a[1];
	dp[2] = dp[1] + a[2];
	dp[3] = Max(dp[2], dp[0]) + a[3];
	dp[4] = Max(dp[3], dp[1]) + a[4];
	for (auto i = 5; i <= n; i++) {
		dp[i] = Max(dp[i - 1], dp[i - 3], dp[i - 5]) + a[i];
	}

	long long index_back = n;
	vector<long long>itog;
	while (index_back != 0) {
		if (index_back - 1 >= 0) if (dp[index_back] == a[index_back] + dp[index_back - 1]) {
			itog.push_back(index_back);
			index_back -= 1;
		}
		if (index_back - 3 >= 0) if (dp[index_back] == a[index_back] + dp[index_back - 3]) {
			itog.push_back(index_back);
			index_back -= 3;
		}
		if (index_back - 5 >= 0) if (dp[index_back] == a[index_back] + dp[index_back - 5]) {
			itog.push_back(index_back);
			index_back -= 5;
		}
	}
	cout << dp[n] << ' ' << itog.size() << '\n';
	for (int i = itog.size() - 1; i >= 0; i--) {
		cout << itog[i] << ' ';
	}
	cout << '\n';
}
