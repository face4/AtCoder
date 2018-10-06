#include<iostream>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    int ans = 1;
    for(int i = 1; i*i <= m; i++){
        if(m % i)   continue;
        if(i >= n)      ans = max(ans, m/i);
        if(m/i >= n)    ans = max(ans, i);
    }

    cout << ans << endl;

    return 0;
}