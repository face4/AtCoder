#include<iostream>
#include<map>
using namespace std;

typedef long long ll;

int main(){
    ll n;
    cin >> n;
    map<ll,int> cnt;
    for(ll i = 2; i*i <= n; i++){
        while(n%i == 0){
            n /= i;
            cnt[i]++;
        }
    }
    if(n > 1)   cnt[n]++;
    int ans = 0;
    for(auto p : cnt){
        int x = p.second;
        for(int i = 0;; i++){
            if(i*(i+1)/2 > x){
                ans += i-1;
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}