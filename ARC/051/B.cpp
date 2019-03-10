#include<iostream>
using namespace std;

typedef long long ll;

int main(){
	ll fib[41];
	fib[0] = fib[1] = 1;
	for (int i = 2; i < 41; i++)	fib[i] = fib[i - 1] + fib[i - 2];
	int k;
	cin >> k;
	cout << fib[k - 1] << " " << fib[k] << endl;
	return 0;
}
