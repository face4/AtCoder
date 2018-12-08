#include<iostream>
using namespace std;

int main(){
    int d;
    cin >> d;

    cout << "Christmas";
    d = 25-d;
    while(d-- > 0)  cout << " Eve";
    cout << endl;
    
    return 0;
}