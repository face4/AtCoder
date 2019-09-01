#include<iostream>
#include<map>
using namespace std;
typedef long long ll;

int main(){
    int a, b;
    cin >> a >> b;
    map<int,int> cnt;
    while(a != b){
        int cp = a;
        for(int i = 2; i*i <= cp; i++){
            if(cp%i)    continue;
            while(cp%i == 0){
                cnt[i]++;
                cp /= i;
            }
        }
        if(cp != 1) cnt[cp]++;
        a--;
    }
    ll ret = 1;
    const ll mod = 1e9 + 7;
    for(auto p : cnt)   ret = ret * (p.second+1) % mod;
    cout << ret << endl;
    return 0;
}