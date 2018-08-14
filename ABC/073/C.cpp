#include<iostream>
#include<set>
using namespace std;

int main(){
	int n;
	cin >> n;
	
	set<int> paper;
	int a;
	
	for(int i = 0; i < n; i++){
		cin >> a;
		set<int>::iterator it = paper.find(a);
		if(it == paper.end()){
			paper.insert(a);
		}else{
			paper.erase(it);
		}
	}
	
	cout << paper.size() << endl;
	
	return 0;
}
