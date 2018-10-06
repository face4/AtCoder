#include<iostream>
#include<climits>
using namespace std;

int main(){
    int n, T;
    cin >> n >> T;

    int c, t;
    int ans = INT_MAX;

    while(n-- > 0){
        cin >> c >> t;
        if(t <= T)  ans = min(ans, c);
    }

    if(ans == INT_MAX){
        cout << "TLE" << endl;
    }else{
        cout << ans << endl;
    }
    
    return 0;
}