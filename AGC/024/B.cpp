// 1ずつ増えていくLISを求めればよい
#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;

    int A[n+1] = {};     
    int B[n+1] = {}; //逆引き

    for(int i = 1; i <= n; i++){
        cin >> A[i];
        B[A[i]] = i;
    }

    // for(int i = 1; i <= n; i++){
    //     cout << B[i] << endl;
    // }

    int forward[n+1] = {};
    for(int i = 1; i <= n; i++){
        if(A[i] == 1)   forward[i] = 1;
        else{
            if(B[A[i]-1] < i)   forward[i] = forward[B[A[i]-1]]+1;
            else                forward[i] = 1;
        }
    }

    int backward[n+1] = {};
    for(int i = n; i >= 1; i--){
        if(A[i] == n)   backward[i] = 1;
        else{
            if(B[A[i]+1] > i)   backward[i] = backward[B[A[i]+1]]+1;
            else                backward[i] = 1;
        }
    }

    sort(forward, forward+n+1);
    sort(backward, backward+n+1);

    // for(int i : forward)   cout << i << " ";
    // cout << endl;
    
    // for(int i : backward)   cout << i << " ";
    // cout << endl;

    int inc = forward[n];
    int dec = backward[n];

    if(inc > dec)   cout << (n-inc) << endl;
    else            cout << (n-dec) << endl;

    return 0;
    
}