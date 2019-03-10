#include<iostream>
using namespace std;

int main(){
    int n, a, b;
    cin >> n >> a >> b;
    if(a >= n){
        cout << "Takahashi" << endl;
    }else if(a == b){
        cout << (n%(a+1) == 0 ? "Aoki" : "Takahashi") << endl;
    }else{
        cout << (a < b ? "Aoki" : "Takahashi") << endl;
    }
    return 0;
}