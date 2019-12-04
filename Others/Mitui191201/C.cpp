#include<iostream>
using namespace std;
#define inRange(x,a,b) (a <= x && x <= b)

int main(){
    int x;
    cin >> x;
    for(int i = 0; i*100 <= x; i++){
        if(inRange(x-i*100, 0, i*5)){
            cout << 1 << endl;
            return 0;
        }
    }
    cout << 0 << endl;
    return 0;
}