#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main(){
	int n;
	cin >> n;
	vector<vector<int>> mas;
	for (auto i = 0; i < n; i++) { mas.push_back({}); }
	for (auto i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (auto j = 0; j < str.size(); j++) {
			if (str[j] == '1') {
				mas[i].push_back(j+1);
			}
		}
	}
	for (auto i = 0; i < n; i++) {
		cout << mas[i].size()<<' ';
		for (auto j : mas[i]) { cout << j << ' '; }
		cout << '\n';
	}
}


