#include<iostream>
#include<vector>
using namespace std;

int gcd(int a, int b){
    return b == 0 ? a : gcd(b, a%b);
}

int main(){
    int n;
    cin >> n;
    vector<int> v(n), cnt(1000001, 0);
    for(int i = 0; i < n; i++)  cin >> v[i], cnt[v[i]]++;
    bool pw = true;
    for(int i = 2; i <= 1000000; i++){
        int tmp = 0;
        for(int j = i; j <= 1000000; j += i)    tmp += cnt[j];
        pw &= tmp < 2;
    }
    if(pw){
        cout << "pairwise coprime" << endl;
    }else{
        int g = v[0];
        for(int i = 1; i < n; i++)  g = gcd(g, v[i]);
        cout << (g==1 ? "setwise coprime" : "not coprime") << endl;
    }
    return 0;
}