#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int main() {
	long long n;
	cin >> n;
	vector<long long> vect = {0};
	for (auto i = 1; i < n+1 ; i++) {
		long long vvod;
		cin >> vvod;
		vect.push_back(vvod);
	}
	vector<long long> znah;
	for (auto i = 0; i < n + 1; i++) { znah.push_back(0); }
	znah[1] = vect[1];
	if (vect[1] > 0)znah[2] = vect[2] + vect[1];
	else znah[2] = vect[2];
	for (auto i = 3; i < n + 1; i++) {
		znah[i] = max(znah[i-1],znah[i-2]) + vect[i];
	}
	cout << znah[n] << '\n';
}
