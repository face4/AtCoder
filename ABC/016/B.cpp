#include<iostream>
using namespace std;

int main(){
	int a, b, c;
	cin >> a >> b >> c;
	bool plus = (a+b)==c;
	bool minus = (a-b)==c;
	
	if(plus&&minus)	cout << "?" << endl;
	if(plus&&!minus)	cout << "+" << endl;
	if(!plus&&minus)	cout << "-" << endl;
	if(!plus&&!minus)	cout << "!" << endl;
	
	return 0;
}