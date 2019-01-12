#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;

ll dec(string s){
    ll ret = 0;
    reverse(s.begin(), s.end());
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '1') ret |= (1ll<<i);
    }
    return ret;
}

int main(){
    ll n;
    cin >> n;

    ll cp = n;
    string bin = "";
    while(cp > 0){
        if(cp%2) bin += "1";
        else    bin += "0";
        cp >>= 1;
    }

    reverse(bin.begin(), bin.end());

    bool taka = true;
    
    if(bin.length()%2){
        for(int i = 1; i < bin.length(); i++)   bin[i] = (i%2==1 ? '1' : '0');
        if(dec(bin) <= n) taka = false;
    }else{
        for(int i = 1; i < bin.length(); i++)   bin[i] = (i%2==0 ? '1' : '0');
        if(dec(bin) > n)  taka = false;
    }
    
    if(taka)    cout << "Takahashi" << endl;
    else        cout << "Aoki" << endl;

    return 0;
}