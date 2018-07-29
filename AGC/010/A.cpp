#include<iostream>
using namespace std;

int main(){
	int n, odd = 0, a;
	cin >> n;
	
	while(n-- > 0){
		cin >> a;
		if(a%2 == 1)	odd++;
	}
	
	if(odd%2)	cout << "NO" << endl;
	else			  cout << "YES" << endl;
	
	return 0;
}
