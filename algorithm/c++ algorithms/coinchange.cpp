#include<iostream>
// dp turuliin algorithm buyu coin change-iin bodlogo
// https://www.hackerrank.com/challenges/coin-change/problem
using namespace std;
long long a[1000];
int main(){
	int n, m, i, j, b[100];
	cin >> n >> m;
	for(i = 0; i < m; i++){
		cin >> b[i];
	}
	a[0] = 1;
	for(i = 0; i < m; i++){
		for(j = b[i]; j <= n; j++){
			a[j] += a[j-b[i]];
		}
	}
	cout << a[n];
}
