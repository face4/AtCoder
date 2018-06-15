#include<iostream>
using namespace std;

int main(){
    char c;
    int cnt = 0;
    for(int i = 0; i < 3; i++){
        cin >> c;
        cnt += c-'0';
    }
    cout << cnt << endl;
    return 0;
}