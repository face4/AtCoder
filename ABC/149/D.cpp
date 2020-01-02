#include<iostream>
#include<vector>
#include<map>
using namespace std;

int main(){
    int n, k, r, s, p;
    cin >> n >> k >> r >> s >> p;
    string S;
    cin >> S;
    map<char,int> m;
    m['r'] = p;
    m['p'] = s;
    m['s'] = r;
    int ret = 0;
    for(int i = 0; i < S.length(); i++){
        if(i >= k && S[i-k] == S[i]){
            S[i] = '?';
        }else{
            ret += m[S[i]];
        }
    }
    cout << ret << endl;
    return 0;
}