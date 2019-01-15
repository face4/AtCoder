// 何で合わないのかわからない.考察が間違っている可能性がある.
#include<iostream>
#include<set>
#include<map>
using namespace std;

typedef long long ll;
const ll mod = 1000000007;

bool x[1000001] = {};
bool y[1000001] = {};

int main(){
    int n, m;
    cin >> n >> m;

    int a[n], b[m];
    bool valid = true;
    map<int,int> reva, revb;

    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(x[a[i]]) valid = false;
        x[a[i]] = true;
        reva[a[i]] = i;
    }

    for(int i = 0; i < m; i++){
        cin >> b[i];
        if(y[b[i]]) valid = false;
        y[b[i]] = true;
        revb[b[i]] = i;
    }

    if(!valid){
        cout << 0 << endl;
        return 0;
    }

    int cnti = 0, cntj = 0;
    ll ans = 1;
    ll vacant = 0;
    
    for(int i = n*m; i >= 1; i--){
        int tmp = 0, add = 0;
        if(reva.count(i)){
            tmp++;
            vacant += cntj;
            add += cntj;
            cnti++;
        }
        if(revb.count(i)){
            tmp++;
            vacant += cnti;
            add += cnti;
            cntj++;
        }

        if(tmp == 2){
            // iは固定
            vacant--;
            continue;
        }

        if(vacant == 0){
            // 空きマス無し
            cout << 0 << endl;
            return 0;
        }

        if(add != 0){
            ans *= add;
        }else{
            ans *= vacant;
        }
        ans %= mod;
        vacant--;
    }

    cout << ans << endl;

    return 0;
}