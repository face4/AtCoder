// coding on smartphone
#include<iostream>
using namespace std;

int main(){
	int n, x, ma = -1000001, mapos, mi = 1000001, mipos;
	cin >> n;
	
	for(int i =0; i < n; i++){
		cin >> x;
		if(x > ma){
			ma = x;
			mapos = i;
		}
		if(x < mi){
			mi = x;
			mipos = i;
		}
	}
	
	cout << 2*n-1 << endl;
	int pivot = (abs(ma) > abs(mi) ? mapos : mipos);
	
	pivot++;
	
	for(int i = 1; i <= n; i++) cout << pivot << " " << i << endl;
	
	if(abs(ma) > abs(mi)){
		for(int i = 1; i < n; i++)   cout << i << " " << i+1 << endl;
	}else{
		for(int i = n; i > 1; i--)	cout << i << " " << i-1 << endl;
	}
	
	return 0;
}
