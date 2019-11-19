#include<iostream>
#include<vector>
#include<list>
using namespace std;

typedef long long ll;

int main(){
    ll n, a, b;
    cin >> n >> a >> b;
    if(a*b < n || a+b-1 > n){
        cout << -1 << endl;
        return 0;
    }
    list<int> ans;
    int now = 1;
    for(int i = 0; i < b; i++){
        int len = min(a, (n-now+1)-(b-1-i));
        for(int j = now+len-1; j >= now; j--)   ans.push_front(j);
        now += len;
    }
    for(auto it = ans.begin(); it != ans.end(); it++){
        cout << *it << " \n"[it==--ans.end()];
    }
    return 0;
}