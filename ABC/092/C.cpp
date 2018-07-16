#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    int a[n+2], sum = 0;
    a[0] = a[n+1] = 0;

    for(int i = 1; i <= n; i++){
        cin >> a[i];
        sum += abs(a[i]-a[i-1]);
    }

    sum += abs(a[n]);

    for(int i = 1; i <= n; i++){
        cout << sum-(abs(a[i-1]-a[i])+abs(a[i]-a[i+1]))+abs(a[i-1]-a[i+1]) << endl;
    }

    return 0;
}