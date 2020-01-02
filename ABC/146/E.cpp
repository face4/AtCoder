#include<iostream>
#include<map>
#include<vector>
using namespace std;
typedef long long ll;

int main(){
    int n, k;
    cin >> n >> k;
    vector<ll> v(n+1, 0);
    for(int i = 1; i <= n; i++)  cin >> v[i], v[i] += v[i-1];
    map<ll,int> m;
    ll ret = 0;
    for(int i = 0; i <= n; i++){
        if(i >= k)   m[(v[i-k]-(i-k))%k]--;
        ret += m[(v[i]-i)%k];  
        m[(v[i]-i)%k]++;
    }
    cout << ret << endl;
    return 0;
}