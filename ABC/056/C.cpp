#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int x;
    cin >> x;

    int sum = 0, t;
    for(t = 1; sum < x; t++)    sum += t;

    cout << --t << endl;

    return 0; 
}