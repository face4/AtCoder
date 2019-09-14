// 他人の解説を読んだ
// 正直あんまりわかってない
#include<iostream>
using namespace std;
typedef long long ll;

const ll INF = 1ll<<60;

int main(){
    int n;
    cin >> n;
    ll x[n], y[n], xm[2], ym[2];
    xm[0] = INF, xm[1] = -INF;
    ym[0] = INF, ym[1] = -INF;
    for(int i = 0; i < n; i++){
        cin >> x[i] >> y[i];
        ll a = x[i]+y[i], b = x[i]-y[i];
        xm[0] = min(xm[0], a);  xm[1] = max(xm[1], a);
        ym[0] = min(ym[0], b);  ym[1] = max(ym[1], b);
    }
    ll D = max(xm[1]-xm[0], ym[1]-ym[0]);   // (座標変換後の座標において)求めたい頂点が乗っている正方形の1辺の長さ
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            ll X = xm[i]+D/2*(i==0?1:-1);
            ll Y = ym[j]+D/2*(j==0?1:-1);
            ll cx = (X+Y)/2, cy = (X-Y)/2;
            bool valid = true;
            ll val = abs(cx-x[0])+abs(cy-y[0]);
            for(int k = 0; k < n; k++){
                valid &= (val == (abs(cx-x[k])+abs(cy-y[k])));
            }
            if(valid){
                cout << cx << " " << cy << endl;
                return 0;
            }
        }
    }
}
