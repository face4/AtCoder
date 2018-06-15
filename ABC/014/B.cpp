#include<iostream>
using namespace std;

int main(){
	int n, x, a, res = 0;
	cin >> n >> x;
	for(int i = 0; i < n; i++){
		cin >> a;
		if(x&1) res += a;
		x = x>>1;
	}
	cout << res << endl;
	return 0;
}
