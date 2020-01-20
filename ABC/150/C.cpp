#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++)  cin >> a[i];
    for(int i = 0; i < n; i++)  cin >> b[i];
    for(int i = 0; i < n; i++){
        if(a[i] == b[i])    continue;
        if(a[i] > b[i]) swap(a, b);
        break;
    }
    int ret = 0;
    do{
        bool x = true;
        for(int i = 0; i < n; i++)  x &= a[i] == b[i];
        if(x)   break;
        ret++;
    }while(next_permutation(a.begin(), a.end()));
    cout << ret << endl;
    return 0;
}