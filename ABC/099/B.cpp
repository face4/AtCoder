#include<iostream>
using namespace std;

int main(){
    int a, b;
    cin >> a >> b;

    int ans = 0;
    while((b-a) * (b-a+1) / 2 != b){
        b++;
        a++;
        ans++;
    }
 
    cout << ans << endl;
    return 0;
}