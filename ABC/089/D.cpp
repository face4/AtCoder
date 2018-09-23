#include<iostream>
using namespace std;

int main(){
    int h, w, d;
    cin >> h >> w >> d;

    int x[90001], y[90001], sum[90001] = {};
    int in;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> in;
            x[in] = i, y[in] = j;
        }
    }

    for(int i = d+1; i <= h*w; i++){
        sum[i] = sum[i-d] + abs(x[i]-x[i-d]) + abs(y[i]-y[i-d]);
    }

    int q;
    cin >> q;

    int l, r;
    for(int i = 0; i < q; i++){
        cin >> l >> r;
        cout << sum[r] - sum[l] << endl;
    }

    return 0;
}