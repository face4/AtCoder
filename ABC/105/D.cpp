// coding on smartphone
#include<iostream>
#include<map>
using namespace std;

typedef long long ll;

int main(){
  int n, m;
  ll ans = 0;
  map<int,ll> appear;
  
  cin >> n >> m;
  ll a[n+1];
  a[0] = 0;
  
  for(int i = 1; i <= n; i++){
    cin >> a[i];
    a[i] += a[i-1];
    appear[a[i]%m]++;
  }
  
  for(pair<int,ll> x : appear){
    if(x.second < 2) continue;
    ans += (x.second) * (x.second - 1) / 2;
  }
  
  if(appear.count(0)) ans += appear[0];
  
  cout << ans << endl;
  
  return 0;
}
