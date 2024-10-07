#include<iostream>
#include<vector>
#include<string>
using namespace std;

string IntToChar(int n) {
	string itog = to_string(n+1);
	return itog; }


int main() {
	int n;
	cin >> n;
	vector<string> vect;
	for (auto i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (auto j = i; j < n; j++) {
			if (str[j] == '1') {
				string strLoc = (string)"" + IntToChar(i) + ' ' + IntToChar(j);
				vect.push_back(strLoc);
			}
		}
	}
	cout << vect.size()<<'\n';
	for (auto i = 0; i < vect.size();i++) {
		cout << vect[ i] << '\n';
	}
}
