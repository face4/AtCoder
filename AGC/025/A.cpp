#include<iostream>
using namespace std;

int main(){
    int n, ans;
    cin >> n;
    if(n%10 == 0){
        ans = 10;
    }else{
        ans = 0;
        while(n>9){
            ans += n%10;
            n /= 10;
        }
        ans += n;
    }
    cout << ans << endl;
    return 0;
}