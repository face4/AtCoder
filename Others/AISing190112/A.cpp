#include<iostream>
using namespace std;

int main(){
    int n, h, w;
    cin >> n >> h >> w;
    cout << (n-w+1) * (n-h+1) << endl;
    return 0;
}