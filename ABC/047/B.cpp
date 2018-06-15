#include<iostream>
using namespace std;

int main(){
    int w, h, n;
    cin >> w >> h >> n;

    int x, y, a;
    int ldx = 0, ldy = 0, rux = w, ruy = h;

    for(int i = 0; i < n; i++){
        cin >> x >> y >> a;
        if(a == 1){
            ldx = max(x,ldx);
        }else if(a == 2){
            rux = min(x,rux);
        }else if(a == 3){
            ldy = max(y, ldy);
        }else if(a == 4){
            ruy = min(y, ruy);
        }
    }

    int ans = max(0, (rux-ldx)) * max(0, (ruy-ldy));
    cout << ans << endl;

    return 0;
}