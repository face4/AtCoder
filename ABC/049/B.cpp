#include<iostream>
using namespace std;

int main(){
    int h , w;
    string row;

    cin >> h >> w;

    for(int i = 0; i < h; i++){
        cin >> row;
        cout << row << endl << row << endl;
    }
    
    return 0;
}