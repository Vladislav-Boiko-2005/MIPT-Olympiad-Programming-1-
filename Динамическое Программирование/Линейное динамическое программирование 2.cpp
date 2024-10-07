#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

vector<long long> a;
vector<long long >b;


long long Maxh(long long v1, long long v2, long long v3) {
	v1 = max(v1, v2);
	v3 = max(v3, v1);
	return v3;
}

int main() {
	long long n;
	cin >> n;
	for (long long i = 0; i < n + 5 + 1; i++) {
		a.push_back(0);
		b.push_back(0);
	}
	for (long long i = 1; i < n + 1; i++) {
		long long vvod;
		cin >> vvod;
		b[i] = vvod;
	}
	for (auto i = 1; i < 6; i++) {
		a[i] = b[i]+a[i-1];
	}
	for (auto i = 3; i < 6; i++) {
		a[i] = max(a[i], a[i - 3] + b[i]);
	}
	for (auto i = 5; i < 6; i++) {
		a[i] = max(a[i], a[i - 5] + b[i]);
	}
	for (long long i = 5; i < n + 1; i++) {
		a[i] = Maxh(a[i -1], a[i-3], a[i-5])+b[i];
	}
	cout << a[n] << '\n';
}
