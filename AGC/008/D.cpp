#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

typedef pair<int,int> pii;

int main(){
    int n;
    cin >> n;
    vector<int> a(n*n, 0);
    int pos = 0;
    vector<pii> vp;
    for(int i = 0; i < n; i++){
        int x;  cin >> x;
        vp.push_back({--x, i+1});
    }
    sort(vp.begin(), vp.end());
    for(int i = 0; i < n; i++){
        int x = vp[i].first;
        int number = vp[i].second;
        a[x] = number;
        int residual = number-1;
        while(residual > 0 && pos < x){
            if(a[pos] == 0) a[pos] = number, residual--;
            pos++;
        }
        if(residual){
            cout << "No" << endl;
            return 0;
        }
    }
    reverse(vp.begin(), vp.end());
    pos = n*n-1;
    for(int i = 0; i < n; i++){
        int x = vp[i].first;
        int number = vp[i].second;
        int residual = n-number;
        while(x < pos && residual > 0){
            if(a[pos] == 0) a[pos] = number, residual--;
            pos--;
        }
        if(residual){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    for(int i = 0; i < n*n; i++)    cout << a[i] << " \n"[i+1==n*n];
    return 0;
}