#include<iostream>
#include<iomanip>
using namespace std;

int gpa(char x){
    if(x == 'A')    return 4;
    if(x == 'B')    return 3;
    if(x == 'C')    return 2;
    if(x == 'D')    return 1;
    if(x == 'F')    return 0;
}

int main(){
    int n;
    cin >> n;

    double sum = 0;
    char x;
    for(int i = 0; i < n; i++){
        cin >> x;
        sum += gpa(x);
    }

    cout << fixed << setprecision(10) << sum/n << endl;

    return 0;
}