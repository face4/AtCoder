#include<iostream>
using namespace std;

int main(){
    bool b[10001] = {};
    b[0] = true;

    int n;
    cin >> n;
    
    while(n-- > 0){
        int p;
        cin >> p;
        for(int i = 10000-p; i >= 0; i--){
            if(b[i])    b[i+p] = true;
        }
    }

    int ans = 0;
    for(int i = 0; i <= 10000; i++) if(b[i])    ans++;

    cout << ans << endl;
    
    return 0;
}

