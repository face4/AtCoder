#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v[n];
    for(int i = 0; i < n; i++){
        string s;   cin >> s;
        for(int j = 0; j < n; j++){
            if(s[j] == '0') continue;
            v[i].push_back(j);
        }
    }
    int ans[n][n];
    memset(ans, 0, sizeof(ans));
    vector<string> b(n);
    for(int i = 0; i < n; i++){
        cin >> b[i];
        for(int j = 0; j < n; j++){
            if(b[i][j] == '1') continue;
            for(int x : v[i]){
                ans[x][j] = -1;
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(b[i][j] == '0') continue;
            bool valid = false;
            for(int x : v[i]){
                valid |= (ans[x][j]==0);
            }
            if(!valid){
                cout << "-1" << endl;
                return 0;
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << ans[i][j]+1;
        }
        cout << endl;
    }
    return 0;
}