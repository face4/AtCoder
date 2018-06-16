#include<iostream>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    n %= 12;
    n = n*60+m;

    double a = 0.5*n;
    double b = 6*m;

    double arch = max(a,b)-min(a,b);

    cout << min(arch, 360-arch) << endl;
    
    return 0;
}