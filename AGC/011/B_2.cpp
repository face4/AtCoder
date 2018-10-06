#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long ll;

int main(){
    int n;
    cin >> n;

    vector<ll> a(n+1);
    a[0] = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    vector<ll> sum(n+1);
    sum[0] = 0;
    for(int i = 1; i <= n; i++){
        sum[i] = sum[i-1] + a[i];
    }

    int t = 0;
    for(int i = 1; i < n; i++){
        if(2*sum[i] < a[i+1])   t = i;
    }

    cout << n-t << endl;

    return 0;
}