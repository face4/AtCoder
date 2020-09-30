#include<iostream>
using namespace std;

typedef long long ll;

int main(){
    int n;
    cin >> n;
    int ma = 0;
    ll ans = 0;
    for(int i = 0; i < n; i++){
        int x;  cin >> x;
        if(x < ma){
            ans += ma-x;
        }else if(x > ma){
            ma = x;
        }
    }
    cout << ans << endl;
    return 0;
}