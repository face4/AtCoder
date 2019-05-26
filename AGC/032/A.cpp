#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    vector<int> a(n), b;
    for(int i = 0; i < n; i++)  cin >> a[i];
    while(b.size() != n){
        int sel = -1;
        for(int i = 0; i < a.size(); i++){
            if(i+1 == a[i] && (sel == -1 || a[i] > a[sel])) sel = i;
        }
        if(sel == -1)   break;
        b.push_back(a[sel]);
        a.erase(a.begin()+sel);
    }
    if(b.size() != n){
        cout << -1 << endl;
    }else{
        for(int i = 0; i < n; i++)  cout << b[n-1-i] << endl;
    }
    return 0;
}