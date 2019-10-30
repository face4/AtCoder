#include<iostream>
using namespace std;

int main(){
    int h, w, a, b;
    cin >> h >> w >> a >> b;
    for(int i = 0; i < b; i++){
        for(int j = 0; j < a; j++){
            cout << 1;
        }
        for(int j = a; j < w; j++){
            cout << 0;
        }
        cout << endl;
    }

    for(int i = b; i < h; i++){
        for(int j = 0; j < a; j++){
            cout << 0;
        }
        for(int j = a; j < w; j++){
            cout << 1;
        }
        cout << endl;
    }
    return 0;
}