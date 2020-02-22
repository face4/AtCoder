#include<iostream>
#include<vector>
using namespace std;

int main(){
    string s;
    cin >> s;
    int n = s.length();
    vector<vector<int>> v(n+1, vector<int>(2,1<<30));
    v[0][0] = 0;
    v[0][1] = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 2; j++){
            for(int k = 0; k < 10; k++){
                int have = j*10+k;
                if(have >= s[i]-'0')    v[i+1][0] = min(v[i+1][0], v[i][j]+have-(s[i]-'0')+k);
                if(have >= s[i]-'0'+1)  v[i+1][1] = min(v[i+1][1], v[i][j]+have-(s[i]-'0'+1)+k);
            }
        }
    }
    cout << v[n][0] << endl;
}
