#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)  cin >> v[i];
    sort(v.begin(), v.end());
    vector<int> fact;
    for(int i = 1; i*i <= v[1]; i++){
        if(v[1]%i == 0){
            fact.push_back(i);
            if(i*i != v[1]) fact.push_back(v[1]/i);
        }
        if(v[0]%i == 0){
            fact.push_back(i);
            if(i*i != v[0]) fact.push_back(v[0]/i);
        }
    }
    sort(fact.rbegin(), fact.rend());
    int ans = 1;
    for(int i = 0; i < fact.size(); i++){
        int cnt = 0;
        int val = fact[i];
        for(int j = 0; j < n; j++){
            cnt += (v[j]%val == 0);
            if(cnt + n-1-j < n-1)   break;
        }  
        if(cnt >= n-1){
            ans = val;
            break;
        }
    }

    cout << ans << endl;

    return 0;
}