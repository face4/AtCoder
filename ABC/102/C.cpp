#include<iostream>
#include<algorithm>
using namespace std;

typedef long long ll;

int main(){
    int n;
    cin >> n;

    ll A[n];
    for(int i = 0; i < n; i++){
        cin >> A[i];
        A[i] -= i+1;
    }  

    sort(A, A + n);

    ll pivot = A[n/2];

    ll ans = 0;
    for(int i = 0; i < n; i++)  ans += abs(A[i] - pivot);

    cout << ans << endl;

    return 0;
}
