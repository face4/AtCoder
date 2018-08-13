#include<iostream>
#include<algorithm>
using namespace std;

int bitcnt(int x){
    int ret = 0;
    while(x > 0){
        if(x & 1)   ret++;
        x = x>>1;
    }
    return ret;
}

int main(){
    string s;
    cin >> s;

    int n = s.length();
    int a[n], b[n];
    for(int i = 0; i < n; i++)  a[i] = (s[i] == 'o');

    int ans = 10000;
    for(int i = 0; i < 1<<n; i++){
        for(int k = 0; k < n; k++)  b[k] = a[k];

        for(int j = 0; j < n; j++){
            if(i & (1<<j)){
                for(int k = 0; k < n; k++){
                    b[(j+k)%n] |= a[k];
                }
            }
            
            bool judge = true;
            for(int k = 0; k < n; k++)  if(b[k] == 0)   judge = false;

            if(judge)   ans = min(ans, bitcnt(i));
        }
    }

    cout << ans+1 << endl;
    
    return 0;
}