#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> v(n);
    map<int,int> m;

    for(int i = 0; i < n; i++){
        cin >> v[i];
        m[v[i]] = i;
    }

    sort(v.begin(), v.end());

    int ans = 0;
    for(int i = 0; i < n; i += 2){
        if(i%2 != m[v[i]]%2){
            ans++;
        }
    }

    cout << ans << endl;
    
    return 0;
}