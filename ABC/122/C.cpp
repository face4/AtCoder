#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n, q;
    string s;

    cin >> n >> q >> s;
    vector<int> v(n, 0);
    for(int i = 1; i < n; i++){
        if(s[i-1] == 'A' && s[i] == 'C')    v[i]++;
    }
    for(int i = 1; i < n; i++)  v[i] += v[i-1];

    int l, r;
    while(q-- > 0){
        cin >> l >> r;
        cout << v[r-1] - v[max(0, l-1)] << endl;
    }
    return 0;
}