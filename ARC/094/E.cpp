// ai > biを満たすbiのうち最小のもの
// 以外をすべて0に出来る気がする
#include<iostream>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    ll sum = 0;
    int mi = 1<<30;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        if(a > b)   mi = min(mi, b);
        sum += a;
    }
    cout << (mi==1<<30 ? 0 : sum-mi) << endl;
    return 0;
}