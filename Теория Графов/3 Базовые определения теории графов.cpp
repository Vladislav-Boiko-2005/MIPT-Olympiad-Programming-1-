#include<iostream>
#include<set>
#include<vector>
#include<string>
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	vector<set<int>> vect;
	for (auto i = 0; i < n+1; i++) { vect.push_back({}); }
	for (auto i = 0; i < m; i++) {
		int vvod, vvod2;
		cin >> vvod >> vvod2;
		vect[vvod].insert(vvod2);
		vect[vvod2].insert(vvod);
	}
	for (auto i = 1; i < vect.size(); i++) {
		string otvet = string (n,'0');
		for (auto j : vect[i]) otvet[j-1] = '1';
		cout << otvet << '\n';
	}
}

