#include<iostream>
#include<cmath>
using namespace std;

int main(){
    string a, b;
    cin >> a >> b;

    int x = stoi(a+b);

    for(int i = 1; i <= sqrt(x); i++){
        if(i*i == x){
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;
    return 0;
}