#include<iostream>
#include<map>
using namespace std;

int main(){
    int n;
    string a, b, c;
    cin >> n >> a >> b >> c;

    int ans = 0;
    for(int i = 0; i < n; i++){
        map<char,int> m;
        m[a[i]]++, m[b[i]]++, m[c[i]]++;
        int z = 0;
        for(auto p : m){
            z = max(z, p.second);
        }
        ans += 3-z;
    }

    cout << ans << endl;
    
    return 0;
}