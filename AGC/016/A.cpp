#include<iostream>
using namespace std;

int main(){
    string s;
    cin >> s;

    int ans = 100;
    for(char i = 'a'; i <= 'z'; i = (char)(i+1)){
        int localMax = 0, cnt = 0;
        for(int j = 0; j < s.length(); j++){
            if(s[j] == i){
                localMax = max(localMax, cnt);
                cnt = 0;
            }else{
                cnt++;
            }
        }
        localMax = max(localMax, cnt);

        ans = min(ans, localMax);
    }

    cout << ans << endl;
    
    return 0;
}