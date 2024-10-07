#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int min_elem(vector<int> name) {
	int minh = name[0];
	for (auto i : name) {
		if (i < minh)minh = i;
	}
	return minh;
}

int main() {
	int n;
	cin >> n;
	vector<int>vect;
	for (auto i = 0; i < n +1+4; i++) {
		vect.push_back(0);
	}
	vect[1] = 0;
	vect[2] = 1;
	vect[3] = 1;
	for (auto i = 4; i < n + 1; i++) {
		vector<int>mas = {vect[i-1]};
		if (i % 2 == 0) {
			mas.push_back(vect[i/2]);
		}
		if (i % 3 == 0) {
			mas.push_back(vect[i/3]);
		}
		int minh = min_elem(mas);
		vect[i] = minh + 1;
	}
	cout << vect[n];
}
