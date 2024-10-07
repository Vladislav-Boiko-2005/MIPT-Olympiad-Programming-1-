#include<iostream>
#include<vector>
#include<set>
using namespace std;


vector<int>smehnoct;
vector <set<int> >list;
vector<bool> passed;


void DFS(int name,int chet) {
	passed[name] = false;
	smehnoct[name] = chet;
	for (auto i : list[name]) {
		if (passed[i]) {
			DFS(i,chet);
		}
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	for (auto i = 0; i < n + 1; i++) {
		smehnoct.push_back(-1);
		list.push_back({});
		passed.push_back(true);
	}
	for (auto i = 0; i < m; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		list[v1].insert(v2);
		list[v2].insert(v1);
	}
	

	int chet_smehnoct = 0;
	for (auto i = 1; i < passed.size(); i++) {
		if (passed[i]) {
			chet_smehnoct += 1;
			DFS(i, chet_smehnoct);
		}
	}
	cout << chet_smehnoct << '\n';
	for (auto i = 1; i < smehnoct.size(); i++) {
		cout << smehnoct[i] <<" ";
	}
}
