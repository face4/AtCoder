#include<iostream>
#include<vector>
#include<map>
using namespace std;
typedef long long ll;

int main(){
    map<char,int> x;
    for(int i = 0; i < 3; i++)  x["RGB"[i]] = i;

    int n;
    string s;
    cin >> n >> s;

    vector<int> v(n);
    for(int i = 0; i < n; i++)  v[i] = x[s[i]];
    
    vector<int> r(3, 0), l(3, 0);
    for(int i = 0; i < n; i++)  r[x[s[i]]]++;
    r[x[s[0]]]--;
    l[x[s[0]]]++;
    ll ret = 0;
    for(int i = 1; i+1 < n; i++){
        for(int j = 0; j < 3; j++){
            if(j == v[i])   continue;
            for(int k = 0; k < 3; k++){
                if(k == j || k == v[i]) continue;
                ret += (ll)l[j]*r[k];
            }
        }
        for(int j = 1; j < n; j++){
            if(i-j < 0 || i+j > n-1)    break;
            ret -= (v[i-j]!=v[i]&&v[i]!=v[i+j]&&v[i+j]!=v[i-j]);
        }
        r[x[s[i]]]--;
        l[x[s[i]]]++;
    }
    cout << ret << endl;
    return 0;
}