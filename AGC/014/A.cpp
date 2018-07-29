#include<iostream>
using namespace std;

int main(){
    int a, b, c;
    cin >> a >> b >> c;

    int ans;
    if(a == b && b == c){
        if(a % 2 == 0)  ans = -1;
        else            ans = 0;
    }else{
        ans = 0;
        while(a%2 == 0 && b%2 == 0 && c%2 == 0){
            int na = (b+c)/2, nb = (c+a)/2, nc = (a+b)/2;
            ans++;
            a = na, b = nb, c = nc;
        }
    }

    cout << ans << endl;
    
    return 0;
}