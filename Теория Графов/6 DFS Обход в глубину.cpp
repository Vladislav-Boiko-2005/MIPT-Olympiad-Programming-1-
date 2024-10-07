#include<iostream>
#include<vector>
#include<set>
#include<string>


using namespace std;
vector<set<int>>list;
vector<int> color;
string flag = "NO";

void DFS(int name, int pred) {
	color[name] = 1;
	for (auto i : list[name]) {
		if (color[i] == 0) { DFS(i, name); }
		if ((color[i] == 1)&&(i!=pred)) {flag = "YES"; }
	}
	color[name] = 3;
}


int main() {
	int n, m;
	cin >> n >> m;
	for (auto i = 0; i < n + 1; i++) { list.push_back({}); color.push_back(0); }
	for (auto i = 0; i < m; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		list[v1].insert(v2);
		list[v2].insert(v1);
	}
	for (auto i = 1; i < n; i++) { DFS(i, i); }
	cout << flag << '\n';
}
