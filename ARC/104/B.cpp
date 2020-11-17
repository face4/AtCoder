#include<iostream>
#include<vector>
#include<map>
using namespace std;

int main(){
    int n;
    string s;
    cin >> n >> s;
    map<char,int> m;
    m['A'] = 0;
    m['T'] = 1;
    m['G'] = 2;
    m['C'] = 3;
    vector<vector<int>> v(4, vector<int>(n+1, 0));
    for(int i = 0; i < n; i++)  v[m[s[i]]][i+1]++;
    for(int i = 0; i < 4; i++){
        for(int j = 1; j <= n; j++) v[i][j] += v[i][j-1];
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = i+1; j <= n; j++){
            int a = v[0][j]-v[0][i-1];
            int b = v[1][j]-v[1][i-1];
            int c = v[2][j]-v[2][i-1];
            int d = v[3][j]-v[3][i-1];
            ans += (a==b)&&(c==d);
        }
    }
    cout << ans << endl;
    return 0;
}