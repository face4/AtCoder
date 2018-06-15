#include<iostream>
using namespace std;

typedef long long ll;

int main(){
    int n , k;
    cin >> n >> k;

    ll A[n];
    for(int i = 0; i < n; i++){
        cin >> A[i];
        if(A[i] == 0){
            cout << n << endl;
            return 0;
        }
    }

    int ans = 0;
    int l = 0, r = 0;
    ll now = 1;

    while(r < n){
        
        if(l > r){
            r = l;
            now = A[r];
        }

        while(r < n && now*A[r] <= k){
            now *= A[r];
            r++;
        }

        ans = max(ans, r-l);

        now /= A[l];
        l++;
    }

    cout << ans << endl;
    return 0;
}