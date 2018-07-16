#include<iostream>
using namespace std;

int main(){
    long long n, m;
    cin >> n >> m;

    if(n == 1 && m == 1)        cout << 1 << endl;
    else if(min(n,m) == 1)      cout << max(n,m)-2 << endl;
    else                        cout << (m-2)*(n-2) << endl;

    return 0;
}