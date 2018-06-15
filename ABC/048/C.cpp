#include<iostream>
using namespace std;

int main(){
    int n, x;
    cin >> n >> x;

    int A[n];
    for(int i = 0; i < n; i++)  cin >> A[i];

    long long ans = 0;

    if(A[0] > x){
        ans += A[0]-x;
        A[0] = x;
    }

    for(int i = 1; i < n; i++){
        if(A[i-1]+A[i] > x){
            ans += A[i]-(x-A[i-1]);
            A[i] = x-A[i-1];
        }
    }

    cout << ans << endl;
    
    return 0;
}