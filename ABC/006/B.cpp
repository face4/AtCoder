#include<iostream>
using namespace std;

int A[1000001];

int main(){
    int n;
    cin >> n;
    
    A[1] = A[2] = 0;
    A[3] = 1;

    for(int i = 4; i <= n; i++){
        A[i] = (A[i-3]+A[i-2]+A[i-1])%10007;
    }

    cout << A[n] << endl;
    return 0;
}