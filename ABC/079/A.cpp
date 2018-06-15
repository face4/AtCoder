#include<iostream>
using namespace std;

int main(){
    char A[4];
    for(int i = 0; i < 4; i++)  cin >> A[i];
    if((A[0]==A[1] && A[1]==A[2]) || (A[1]==A[2] && A[2]==A[3])){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

    return 0;
}