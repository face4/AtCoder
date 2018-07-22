#include<iostream>
using namespace std;

int main(){
    int n, o;
    cin >> n >> o;

    for(int x = o/10000; x >= 0; x--){
        for(int y = (o-x*10000)/5000; y >= 0; y--){
            int z = (o-x*10000-y*5000)/1000;
            if(x+y+z == n){
                cout << x << " " << y << " " << z << endl;
                return 0;
            }
        }
    }

    cout << "-1 -1 -1" << endl;
    return 0;
}