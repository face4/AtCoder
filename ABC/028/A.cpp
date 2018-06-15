#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    if(n <= 59)             cout << "Bad" << endl;
    if(60 <= n && n <= 89)  cout << "Good" << endl;
    if(90 <= n && n <= 99)  cout << "Great" << endl;
    if(n == 100)            cout << "Perfect" << endl;

    return 0;
}