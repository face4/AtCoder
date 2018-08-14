#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	int n;
	cin >> n;
	
	set<int> dou;
	vector<int> can;
	
	int a;
	for(int i = 0; i < n; i++){
		cin >> a;
		if(dou.find(a) != dou.end()){
			can.push_back(a);
			dou.erase(dou.find(a));
		}else{
			dou.insert(a);
		}
	}
	
	if(can.size() < 2){
		cout << 0 << endl;
	}else{
		sort(can.begin(), can.end());
		cout << (long long)(can[can.size()-1]) * can[can.size()-2] << endl;
	}
	
	return 0;
}
