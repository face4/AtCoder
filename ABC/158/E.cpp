// editorial
#include<iostream>
#include<map>
using namespace std;

typedef long long ll;

int main(){
    int n, p;
    cin >> n >> p;
    string s;
    cin >> s;
    ll ans = 0;
    if(p == 2 || p == 5){
        for(int i = 0; i < n; i++)  ans += (i+1)*((s[i]-'0')%p==0);
        cout << ans << endl;
        return 0;
    }
    map<int,int> cnt;
    cnt[0]++;
    int acc = 0, ten = 1;
    for(int i = 0; i < n; i++){
        acc = (ten*(s[n-1-i]-'0')+acc)%p;
        ans += cnt[acc];
        cnt[acc]++;
        (ten *= 10) %= p;
    }
    cout << ans << endl;
    return 0;
}