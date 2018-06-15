#include<iostream>
#include<cmath>
using namespace std;

int main(){
	int n, num = 0, tmp, sum = 0;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> tmp;
		if(tmp){
			sum += tmp;
			num++;
		}
	}
	cout << ceil(double(sum)/num) << endl;
	return 0;
}
