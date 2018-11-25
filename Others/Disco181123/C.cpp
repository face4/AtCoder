// coding on smartphone
#include<iostream>
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;

int main(){
	ll n;
	cin >> n;
	
	ll memo[n+1];
	memo[0] = 0;
	for(ll i = 1; i <= n; i++){
		memo[i] = i;
		for(int k = 1; k < 10; k++){
			memo[i] *= i;
			memo[i] %= mod;
		}
	}
	
	ll ans = 0;
	for(ll i = 1; i <= n; i++){
		ans += (memo[i]-memo[i-1]+mod)*(memo[n/i]);
		ans %= mod;
	}
	
	cout << ans << endl;
	
	return 0;
}

