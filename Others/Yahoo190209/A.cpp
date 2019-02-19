#include<iostream>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    if((n+1)/2 >= k)    cout << "YES" << endl;
    else                cout << "NO" << endl;
    return 0;
}