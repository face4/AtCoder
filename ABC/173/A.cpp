#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    cout << (n+999)/1000*1000-n << endl;
    return 0;
}