#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    int x = (n/5) % 6;
    n %= 5;

    int A[6];
    for(int i = 0; i < x; i++){
        A[6-x+i] = i+1;
    }

    for(int i = 0; i < 6-x; i++){
        A[i] = x+i+1;
    }

    for(int i = 0; i < n; i++){
        swap(A[i], A[i+1]);
    }

    for(int al : A) cout << al;
    cout << endl;

    return 0;
}