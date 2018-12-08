#include<iostream>
using namespace std;

int main(){
    int n, sum = 0, ma = -1;
    cin >> n;

    int tmp;
    while(n-- > 0){
        cin >> tmp;
        sum += tmp;
        ma = max(tmp, ma);
    }
    sum -= ma/2;

    cout << sum << endl;
    
    return 0;
}