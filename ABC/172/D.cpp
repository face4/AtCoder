#include<iostream>
using namespace std;

typedef long long ll;

int main(){
  ll n;
  cin >> n;
  ll ans = 0;
  for(ll i = 1; i <= n; i++){
    ans += n/i*(2*i+(n/i-1)*i)/2;
  }
  cout << ans << endl;
  return 0;
}
