#include<iostream>
using namespace std;

int main(){
    int r, g, b;
    cin >> r >> g >> b;

    int cnt[301] = {};
    for(int i = 1; i <= 300; i++){
        cnt[i] = cnt[i-1] + i;
    }

    int ans = 1e9;
    // greenを0番の箱に入れることが最善とは限らない(らしい.by解説)
    // greenの左端を全探索
    for(int i = -300; i <= 300; i++){
        int tmp = 0;
        for(int j = 0; j < g; j++){
            tmp += abs(i+j);
        }
        if(i <= -100){
            tmp += r*(-100-i+1);
            tmp += cnt[r-1];
        }else if((r-1)/2 >= i-1+100){
            tmp += cnt[i-1+100];
            tmp += cnt[r-1-(i-1+100)];
        }else{
            tmp += cnt[(r-1)/2] + cnt[r-1-(r-1)/2];
        }
        int j = i+g-1;
        if(j >= 100){
            tmp += b*(j-100+1);
            tmp += cnt[b-1];
        }else if((b-1)/2 >= 99-(j+1)+1){
            tmp += cnt[99-(j+1)+1];
            tmp += cnt[b-1-(99-(j+1)+1)];
        }else{
            tmp += cnt[(b-1)/2] + cnt[b-1-(b-1)/2];
        }
        ans = min(ans, tmp);
    }

    cout << ans << endl;

    return 0;
}