#include<iostream>
using namespace std;

bool isLeap(int x){
    if(x%4 == 0 && x%100 != 0)  return true;
    if(x%400 == 0) return true;
    return false;
}

int main(){
    int y;
    cin >> y;
    if(isLeap(y))   cout << "YES" << endl;
    else            cout << "NO" << endl;
    return 0;
}