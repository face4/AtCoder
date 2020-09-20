#include<iostream>
using namespace std;

int main(){
    int a, b;
    cin >> a >> b;
    for(int i = 0; i <= b*100; i++){
        int x = (int)((double)i*0.08);
        int y = (int)((double)i*0.10);
        if(x == a && y == b){
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}