#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    int a[n+1];
    a[0] = 0;
    for(int i = 1; i <= n; i++)  cin >> a[i];

    int r = 0;
    long long ans = 0;
    for(int l = 1; l <= n; l++){
        if(l > r)   r = l;
        while(r+1 <= n && a[r+1] > a[r]){
            r++;
        }
        ans += (long long)(r-l+1);
    }

    cout << ans << endl;

    return 0;
}