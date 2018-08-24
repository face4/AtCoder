#include<iostream>
using namespace std;

int main(){
    bool nonprime[1000001] = {};
    nonprime[0] = nonprime[1] = true;
    for(int i = 2; i < 1000001; i++){
        if(!nonprime[i]){
            for(int j = i+i; j < 1000001; j += i){
                nonprime[j] = true;
            }
        }
    }

    int n;
    cin >> n;

    cout << (!nonprime[n] ? "YES" : "NO") << endl;

    return 0;
}