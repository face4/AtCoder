#include<iostream>
using namespace std;

int main(){
    int x, y;
    cin >> x >> y;
    for(int i = 0; i <= y/2; i++){
        int z = 2*i;
        if(y-z >= 0 && (y-z)%4==0 && (y-z)/4+i==x){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}