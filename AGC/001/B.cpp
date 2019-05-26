#include<iostream>
using namespace std;
typedef long long ll;

// 解説を見た
int main(){
    ll n, x;
    cin >> n >> x;
    
    // 最初の2回分の反射
    ll ans = x + n-x; // virtually n

    /// a, bからなる平行四辺形が出来る
    ll a = max(n-x, x), b = min(n-x, x);
    
    while(b != 0){
        // 図示するとわかるが(x > n/2とするとわかりやすい)、
        // 平行四辺形内を光が反射しまくって
        // 新しい平行四辺形を作り上げるとき、長辺aの長さを短辺b
        // の長さで割ったときの商(切り捨て)の2倍だけ長さbの軌跡が残る
        // 新しく出来る平行四辺形の長さはb, a%b(euclidそのもの)
        ans += a/b*2*b;
        ll tmp = a;
        a = b;
        b = tmp%b;
    }

    // 最後(平行四辺形でなくなってしまう)とき、bを1回余計に足している
    // これは、最後の平行四辺形内の軌跡を構成する線分群のうち、
    // 1辺だけ既にもっと長い線分の一部として計算済であることからわかる
    // そのときのbはaに格納されているので、ansからaを引く
    cout << ans-a << endl;

    return 0;
}