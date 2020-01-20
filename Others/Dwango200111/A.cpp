#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    string s[n];
    int t[n];
    for(int i = 0; i < n; i++)  cin >> s[i] >> t[i];
    string x;
    cin >> x;
    for(int i = 0; i < n; i++){
        if(s[i] == x){
            int ret = 0;
            for(int j = i+1; j < n; j++)    ret += t[j];
            cout << ret << endl;
            return 0;
        }
    }
}