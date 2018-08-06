#include<iostream>
using namespace std;

string tmp[3] = {"TAKAHASHIKUN", "Takahashikun", "takahashikun"};

bool check(string x){
    for(int i = 0; i < 3; i++){
        if(x == tmp[i]) return true;
    }
    return false;
}

int main(){
    int n;
    cin >> n;

    int ans = 0;
    string x;
    for(int i = 0; i < n-1; i++){
        cin >> x;
        if(check(x))    ans++;
    }

    cin >> x;
    x = x.substr(0, x.length()-1);

    if(check(x))    ans++;

    cout << ans << endl;
    return 0;
}