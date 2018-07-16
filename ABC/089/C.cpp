#include<iostream>
using namespace std;

typedef long long ll;

int main(){
    ll march[5] = {};
    int n;
    string s;

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s;
        if(s[0] == 'M') march[0]++;
        if(s[0] == 'A') march[1]++;
        if(s[0] == 'R') march[2]++;
        if(s[0] == 'C') march[3]++;
        if(s[0] == 'H') march[4]++;        
    }

    ll res = 0;
    for(int i = 0; i < 3; i++){
        for(int j = i+1; j < 4; j++){
            for(int k = j+1; k < 5; k++){
                res += march[i]*march[j]*march[k];
            }
        }
    }

    cout << res << endl;

    return 0;
}