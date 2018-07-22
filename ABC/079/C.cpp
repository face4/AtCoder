#include<iostream>
using namespace std;

int main(){
    int x, a[4], op[3];
    cin >> x;

    for(int i = 3; i >= 0; i--){
        a[i] = x%10;
        x /= 10;
    }

    for(int i = 0; i < (1<<3); i++){
        int accum = a[0];
        for(int j = 2; j >= 0; j--){
            op[2-j] = ((i&(1<<j)) != 0);
            if(op[2-j] == 1)  accum += a[3-j];
            else              accum -= a[3-j];    
        }

        if(accum == 7){
            for(int i = 0; i < 3; i++){
                cout << a[i];
                if(op[i] == 1)  cout << "+";
                else            cout << "-";
            }
            cout << a[3] << "=7" << endl;
            return 0;
        }
    }
}