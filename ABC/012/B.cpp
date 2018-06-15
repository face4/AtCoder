#include<iostream>
using namespace std;

int main(){
	int n, h, m, s;
	cin >> n;
	
	h = n/3600;
	n -= h*3600;
	m = n/60;
	n -= m*60;
	s = n;
	
	cout << (h < 10 ? "0" : "") << h << ":"
	         << (m < 10 ? "0" : "") << m << ":"
	         << (s < 10 ? "0" : "") << s << endl;
	
	return 0;
}
