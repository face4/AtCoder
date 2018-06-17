#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int n;
    cin >> n;

    int ans = 1<<21;
    int h, w;
    for(h = 1; h <= sqrt(n); h++){
        for(w = 1; h*w <= n; w++){
            ans = min(ans, abs(w-h)+n-h*w);  
        }
    }
    
    cout << ans << endl;
    return 0;
}