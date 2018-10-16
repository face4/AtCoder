#include<iostream>
using namespace std;

int main(){
    int n, x;
    cin >> n >> x;

    int a[n], b[n];
    for(int i = 0; i < n; i++)  cin >> a[i] >> b[i];

    int ma = 0, pos = 0;
    for(int i = 0; i < n; i++){
        if(ma < b[i]){
            ma = b[i];
            pos = i;
        }
    }

    a[pos] += x;

    int ans = 0;
    for(int i = 0; i < n; i++)  ans += a[i]*b[i];

    cout << ans << endl;

    return 0;
}