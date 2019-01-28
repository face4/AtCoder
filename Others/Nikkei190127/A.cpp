#include<iostream>
using namespace std;

int main(){
    int n, a, b;
    cin >> n >> a >> b;

    cout << min(a,b) << " " << max(0, a+b-2) << endl;

    return 0;
}