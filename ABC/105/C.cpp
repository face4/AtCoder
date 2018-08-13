// coding on smartphone
#include<iostream>
using namespace std;

int main(){
	int n;
	cin >> n;
	if(n == 0){
		cout << 0 << endl;
		return 0;
    }
    
    string res = "";
  
	while(n != 0){
		if (n % 2 == 0) res = "0" + res;
		else            n--, res = "1" + res;
		n /= -2;
	}

    cout << res << endl;
    
    return 0;
}
