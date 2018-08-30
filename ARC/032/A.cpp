#include<iostream>
using namespace std;

int isPrime(int x){
    if(x == 1)  return false;
    for(int i = 2; i*i <= x; i++)   if(x%i == 0)    return false;
    return true;
}

int main(){
    int n;
    cin >> n;

    n = n*(n+1)/2;
    if(isPrime(n))  cout << "WANWAN" << endl;
    else            cout << "BOWWOW" << endl;

    return 0;
}