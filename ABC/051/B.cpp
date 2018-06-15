#include<iostream>
using namespace std;

int main(){
    int k, s;
    cin >> k >> s;

    long long ans = 0;

    for(int x = 0; x <= k; x++){
        // 枝狩り
        if(x > s || s-x > 2*k)  continue;
        for(int y = 0; y <= k; y++){
            int z = s-x-y;
            if(0 <= z && z <= k)    ans++;
        }
    }

    cout << ans << endl;
    
    return 0;
}