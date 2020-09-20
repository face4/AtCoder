#include<iostream>
using namespace std;

int cnt[1000001] = {};

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
        cnt[a[i]]++;
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        bool f = false;
        for(int j = 1; j*j <= a[i]; j++){
            if(a[i]%j)  continue;
            int x = j;
            if(cnt[x] > (x==a[i]))    f = true;
            x = a[i]/j;
            if(cnt[x] > (x==a[i]))    f = true;
        }
        if(!f)  ans++;
    }
    cout << ans << endl;
    return 0;
}