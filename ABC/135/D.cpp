#include<iostream>
#include<vector>
using namespace std;
const int mod = 1e9+7;

int main(){
    string s;
    cin >> s;
    int n = s.length();
    vector<vector<int>> v(n+1, vector<int>(13, 0));
    v[0][0] = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 13; j++){
            if(s[i] == '?'){
                for(int k = 0; k < 10; k++){
                    int next = (j*10+k)%13;
                    v[i+1][next] += v[i][j];
                    v[i+1][next] %= mod;
                }
            }else{
                int next = (j*10+(s[i]-'0'))%13;
                v[i+1][next] += v[i][j];
                v[i+1][next] %= mod;
            }
        }
    }
    cout << v[n][5] << endl;
    return 0;
}