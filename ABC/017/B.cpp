#include<iostream>
#include<algorithm>
using namespace std;
	
int main(){
	string s;
	cin >> s;
    int n = s.length();
	for(int i = 0; i < n; i++){
		if(i < n-1 && s[i]=='c' && s[i+1]=='h'){
			i++;
		}else if(s[i]!='o' && s[i]!='k' && s[i]!='u'){
			cout << "NO" << endl;
			return 0;
		}
	}
	
	cout << "YES" << endl;
	return 0;
}
