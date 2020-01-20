#include<iostream>
using namespace std;

int main(){
    int n;
    string s;
    cin >> n >> s;
    int ret = 0;
    for(int i = 0; i+2 < n; i++){
        if(s.substr(i,3)=="ABC")    ret++;
    }
    cout << ret << endl;
    return 0;
}