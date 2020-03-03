#include<iostream>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    int t[m], c[m];
    for(int i = 0; i < m; i++)  cin >> t[i] >> c[i];
    int ret = -1;
    for(int i = 0; i < 1000; i++){
        string s = to_string(i);
        if(s.length() != n) continue;
        bool val = true;
        for(int j = 0; j < m; j++)  val &= s[t[j]-1]-'0'==c[j];
        if(val){
            ret = i;
            break;
        }
    }
    cout << ret << endl;
    return 0;
}