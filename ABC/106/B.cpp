#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin >> n;

    int ans = 0;

    for(int i = 105; i <= n; i+=2){
        int tmp = 0;
        for(int j = 1; j <= i; j++){
            if(i % j == 0)  tmp++;
        }
        if(tmp == 8)    ans++;
    }

    cout << ans << endl;
    
    return 0;
}