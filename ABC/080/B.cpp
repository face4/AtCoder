#include<iostream>
using namespace std;

int main(){
    int x;
    cin >> x;

    int tmp = x;
    int fx = 0;

    while(tmp > 0){
        fx += tmp%10;
        tmp /= 10;
    }

    if(x%fx == 0)   cout << "Yes" << endl;
    else            cout << "No" << endl;

    return 0;
}