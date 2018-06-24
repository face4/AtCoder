#include<iostream>
#include<iomanip>
#include<algorithm>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    int A[n];
    for(int i = 0; i < n; i++)  cin >> A[i];
    sort(A, A+n);
    double rate = 0;
    for(int i = n-k; i < n; i++){
        rate = (rate+A[i]) / 2.0;
    }
    cout << fixed << setprecision(6) << rate << endl;
    return 0;
}