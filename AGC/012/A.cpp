#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;

    long long a[3*n];
    for(int i = 0; i < 3*n; i++)  cin >> a[i];
    sort(a, a+3*n);

    long long ans = 0;
    for(int i = n; i < 3*n; i+=2){
        ans += a[i];
    }

    cout << ans << endl;
    return 0;
}