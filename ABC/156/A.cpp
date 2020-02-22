#include<iostream>
using namespace std;

int main(){
    int n, r;
    cin >> n >> r;
    if(n < 10)  r += 100*(10-n);
    cout << r << endl;
    return 0;
}