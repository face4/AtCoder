#include<iostream>
using namespace std;

int main(){
    int a, b;
    cin >> a >> b;

    if(a > 0)   cout << "Positive" << endl;
    else if(a <= 0 && b >= 0)   cout << "Zero" << endl;
    else{
        if((b-a+1)%2 == 1)  cout << "Negative" << endl;
        else                cout << "Positive" << endl;
    } 

    return 0;
}