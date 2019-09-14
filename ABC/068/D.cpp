#include<iostream>
using namespace std;
typedef long long ll;

int main(){
    ll k;
    cin >> k;
    ll ans[50];
    for(int i = 0; i < 50; i++) ans[i] = i + k/50;
    k %= 50;
    for(int i = 0; i < k; i++){
        for(int j = 0; j < 50; j++){
            if(i==j)    ans[j]+=50;
            else        ans[j]--;
        }
    }
    cout << 50 << endl;
    for(int i = 0; i < 50; i++) cout << ans[i] << " \n"[i+1==50];
    return 0;
}
