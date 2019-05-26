#include<iostream>
using namespace std;
typedef long long ll;

int main(){
    int n, l;
    cin >> n >> l;
    ll a[n];
    for(int i = 0; i < n; i++)  cin >> a[i];
    int ans;
    for(ans = 1; ans < n; ans++){
        if(a[ans]+a[ans-1] >= l)    break;
    }
    if(ans == n){
        cout << "Impossible" << endl;
    }else{
        cout << "Possible" << endl;
        for(int i = 1; i < ans; i++)    cout << i << endl;
        for(int i = n-1; i > ans; i--)  cout << i << endl;
        cout << ans << endl;
    }
    return 0;
}