#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

bool check(int n){
    string s = to_string(n);
    sort(s.begin(), s.end());
    return s[0] == s[s.length()-1];
}

int main(){
    int n;
    cin >> n;

    for(int i = n;; i++){
        if(check(i)){
            cout << i << endl;
            return 0;
        }
    }
}