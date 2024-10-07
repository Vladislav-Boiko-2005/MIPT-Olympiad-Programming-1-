#include<iostream>
#include<vector>
#include<set>
using namespace std;

vector<bool>proiden;
vector<set<int>> list;
vector<int> otvet;


void DFS(int name, int proh) {
	otvet.push_back(name);
	proiden[name] = false;
	for (auto i : list[name]) {
		if (proiden[i]) {
			DFS(i,name);
		}
	}
	otvet.push_back(proh);
}



int main() {
	int n, m;
	cin >> n >> m;
	for (auto i = 0; i < n +1; i++) { list.push_back({}); }
	for (auto i = 0; i < n + 1; i++) { proiden.push_back(true); }
	for (auto i = 0; i < m;i++) {
		int v1, v2;
		cin >> v1 >> v2;
		list[v1].insert(v2);
		list[v2].insert(v1);
	}

	int vvod;
	cin >> vvod;
	DFS(vvod,vvod);
	otvet.pop_back();
	cout << otvet.size() << '\n';
	for (auto i : otvet) { cout << i << ' '; }
}

