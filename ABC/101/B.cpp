#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    int sn = 0;
    int tmp = n;

    while(tmp > 0){
        sn += tmp%10;
        tmp /= 10;
    }

    if(n % sn == 0){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

    return 0;
}