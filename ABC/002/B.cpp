#include<iostream>
using namespace std;

bool check(char c){
	return c == 'a' || c == 'i' ||
		  c == 'u' || c == 'e' || c == 'o';
}

int main(){
	string s;
	cin >> s;
	for(int i = 0; i < s.size(); i++){
		if(!check(s[i])) cout<<s[i];
	}
	cout<<endl;
	
	return 0;
}

