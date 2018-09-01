#include<iostream>
using namespace std;

bool isPrime(int n){
    if(n == 1)  return false;
    if(n == 2)  return true;

    for(int i = 2; i*i <= n; i++)   if(n % i == 0)  return false;

    return true;
}

bool isPrimeLike(int n){
    int digitsum = 0, copy = n;
    while(copy != 0){
        digitsum += copy%10;
        copy /= 10;
    }

    if(isPrime(n))  return true;
    else            if(n % 2 != 0 && n % 10 != 5 && digitsum % 3 != 0)  return true;

    return false;
}

int main(){
    int n;
    cin >> n;

    if(n == 1)          cout << "Not Prime" << endl;
    else if(isPrimeLike(n))  cout << "Prime" << endl;
    else                cout << "Not Prime" << endl;

    return 0;
}