#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	int n;
	cin >> n;
	
	int appear[100002];
	for(int i = 0; i < 100002; i++)	appear[i] = 0;
	
	int a;
	for(int i = 0; i < n; i++){
		cin >> a;
		a++;
		appear[a-1]++;
		appear[a]++;
		appear[a+1]++; 
	}
	
	sort(appear, appear + 100002);
	
	cout << appear[100001] << endl;
	
	return 0;
}
