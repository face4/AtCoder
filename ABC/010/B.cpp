#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    int ans = 0;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        while(x%2 == 0 || x%3==2){
            x--;
            ans++;
        }
    }

    cout << ans << endl;
    return 0;
}