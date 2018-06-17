#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    int A[n];
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }

    sort(A, A+n);
    reverse(A, A+n);

    int res = 0;
    for(int i = 0; i < n; i++){
        if(i%2) res -= A[i];
        else    res += A[i];
    }

    cout << res << endl;
    return 0;
}