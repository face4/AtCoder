#include<iostream>
#include<iomanip>
using namespace std;

typedef long long ll;

int main(){
    int n, a, b;
    cin >> n >> a >> b;

    int _min = 1e9+1, _max = 0, s;
    double ave = 0;

    for(int i = 0; i < n; i++){
        cin >> s;
        _min = min(_min, s);
        _max = max(_max, s);
        ave += s / (double)n;
    }

    if(_min == _max){
        cout << -1 << endl;
        return 0;
    }
    
    double p = (double)b / abs(_max - _min);
    double q = a - p * ave;

    cout << fixed << setprecision(7) << p << " " << q << endl;

    return 0;
}