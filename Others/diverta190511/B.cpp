#include<iostream>
using namespace std;

int main(){
    int r, g, b, n;
    cin >> r >> g >> b >> n;
    int ans = 0;
    for(int i = 0; i <= 3000/r; i++){
        if(i*r > n) break;
        for(int j = 0; j <= 3000/g; j++){
            if(i*r+j*g > n) break;
            if((n-i*r-j*g)%b == 0)  ans++;
        }
    }
    cout << ans << endl;
    return 0;
}