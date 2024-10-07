#include<iostream>
#include<vector>
#include<cmath>
using namespace std;


int main() {
	int m, n;
	cin >> m >> n;
	vector<vector<int>>h;
	vector<vector<int>>delta;

	for (auto i = 0; i < n; i++) {
		h.push_back({});
		delta.push_back({});
		for (auto j = 0; j < m; j++) {
			h[i].push_back(i);
			delta[i].push_back(i);
		}
	}
	for (auto i = 0; i < n; i++) {
		for (auto j = 0; j < m; j++) {
			int vvod;
			cin >> vvod;
			h[i][j] = vvod;
		}
	}
	delta[0][0] = 0;
	for (auto i = 1; i < m; i++) { delta[0][i] = abs(h[0][i] - h[0][i - 1]) + delta[0][i - 1]; }
	for (auto i = 1; i < n; i++) { delta[i][0] = abs(h[i - 1][0] - h[i][0]) + delta[i - 1][0]; }
	for (auto i = 1; i < n; i++) {
		for (auto j = 1; j < m; j++) {
			delta[i][j] = min((abs(h[i][j - 1] - h[i][j]) + delta[i][j - 1]), (abs(h[i - 1][j] - h[i][j]) + delta[i - 1][j]));
		}
	}
	cout << delta[n - 1][m - 1] << '\n';
}



