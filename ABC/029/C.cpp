#include<iostream>
using namespace std;

void solve(string x, int i){
    if(i == 0){
        cout << x << endl;
    }else{
        solve(x+"a", i-1);
        solve(x+"b", i-1);
        solve(x+"c", i-1);
    }
}

int main(){
    int n;
    cin >> n;
    solve("", n);
    return 0;
}