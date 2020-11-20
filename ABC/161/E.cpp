// editorial
#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n, k, c;
    cin >> n >> k >> c;
    string s;
    cin >> s;
    vector<int> r(n, -1), l(n, -1);
    int tim = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == 'x') continue;
        r[tim++] = i;
        i += c;
    }
    tim = k-1;
    for(int i = n-1; i >= 0; i--){
        if(s[i] == 'x') continue;
        l[tim--] = i;
        if(tim < 0) break;
        i -= c;
    }
    for(int i = 0; i < k; i++){
        if(r[i] == l[i])    cout << r[i]+1 << endl;
    }
    return 0;
}