#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    int ans = 0;
    
    int s[n], a[n];
    for(int i = 0; i < n; i++)  cin >> s[i];
    for(int i = 0; i < n; i++)  cin >> a[i];

    for(int i = 0; i < n; i++)  ans = max(ans, s[i]*a[i]);

    cout << ans << endl;
    return 0;
}