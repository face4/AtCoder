#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    int h[n];
    for(int i = 0; i < n; i++)  cin >> h[i];

    int ans = 0;

    while(true){
        int i;
        for(i = 0; i < n; i++)  if(h[i])    break;
        if(i == n)  break;

        ans++;
        for(int j = i; j < n; j++){
            if(h[j] == 0)   break;
            h[j]--;
        }
    }

    cout << ans << endl;
    
    return 0;
}