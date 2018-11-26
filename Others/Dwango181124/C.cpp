#include<iostream>
using namespace std;

typedef long long ll;

int main(){
  int n;
  string s;

  cin >> n >> s;

  int q;
  cin >> q;

  while(q-- > 0){
    int k;
    cin >> k;

    ll ans = 0;
    int cntd = 0, cntm = 0;
    ll cntdm = 0;
    for(int i = 0; i < n; i++){
      if(s[i] == 'D'){
	cntd++;
      }else if(s[i] == 'M'){
	cntm++;
	cntdm += cntd;
      }

      if(s[i] == 'C'){
	ans += cntdm;
      }

      if(i >= k-1){
	if(s[i-(k-1)] == 'D'){
	  cntdm -= cntm;
	  cntd--;
	}else if(s[i-(k-1)] == 'M'){
	  cntm--;
	}
      }
    }

    cout << ans << endl;
    
  }// end of while

  return 0;
}
