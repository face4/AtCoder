#include<iostream>
using namespace std;

int main(){
    int n, m;
    char x;
    cin >> n >> m;

    int name[26] = {}, kit[26] = {};

    for(int i = 0; i < n; i++){
        cin >> x;
        name[x-'A']++;
    }
    for(int i = 0; i < m; i++){
        cin >> x;
        kit[x-'A']++;
    }

    int ans = 0;
    for(int i = 0; i < 26; i++){
        if(name[i]){
            if(kit[i] == 0){
                ans = -1;
                break;
            }else{
                ans = max(ans, (name[i]+kit[i]-1)/kit[i]);
            }
        }
    }

    cout << ans << endl;
    return 0;
}