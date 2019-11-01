#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)  cin >> a[i];
    ll ret = 0, now = 0;
    for(int i = n-1; i >= 0; i--){
        if(now == a[i]){
            // there's nothing to do with a[i]
        }else if(now > a[i]){
            cout << -1 << endl;
            return 0;
        }else if(now < a[i]){
            now = a[i];
            if(now > i){
                cout << -1 << endl;
                return 0;
            }else{
                ret += now;
            }
        }
        now--;
        if(now < 0) now = 0;
    }
    cout << ret << endl;
    return 0;
}