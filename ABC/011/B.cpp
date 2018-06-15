#include<iostream>
#include<algorithm>
using namespace std;
	
int main(){
	string s;
	cin >> s;
	
	for(int i = 0; i < s.size(); i++){
		if(i)	s[i] = tolower(s[i]);
		else	s[i] = toupper(s[i]);
	}
	
	cout << s << endl;
	return 0;
}
