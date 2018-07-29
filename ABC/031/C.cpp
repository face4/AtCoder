#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    int a[n];
    for(int i = 0; i < n; i++)  cin >> a[i];

    int ans = -100000000;
    for(int taka = 0; taka < n; taka++){
        int aokiscore = -10000000, takascore;
        for(int aoki = 0; aoki < n; aoki++){
            if(taka == aoki)    continue;
            int from = min(taka,aoki);
            int to = max(taka,aoki);
            int tmpaoki = 0, tmptaka = 0;
            for(int i = 0; i < to-from+1; i++){
                if(i%2 == 0)    tmptaka += a[from+i];
                else            tmpaoki += a[from+i];
            }

            if(tmpaoki > aokiscore){
                aokiscore = tmpaoki;
                takascore = tmptaka;
            }
        }
        ans = max(ans, takascore);
    }

    cout << ans << endl;

    return 0;
}