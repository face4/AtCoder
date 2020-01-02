#include<iostream>
using namespace std;

int main(){
    int x;
    cin >> x;
    while(true){
        bool b = false;
        for(int i = 2; i*i <= x; i++){
            if(x%i == 0){
                b = true;
                break;
            }
        }
        if(b){
            x++;
            continue;
        }
        cout << x << endl;
        return 0;
    }
}