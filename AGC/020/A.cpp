#include<iostream>
using namespace std;

int main(){
    int n, a, b;
    cin >> n >> a >> b;

    if((abs(a-b)-1 + 2) % 2 == 0){
        cout << "Borys" << endl;
    }else{
        cout << "Alice" << endl;
    }

    return 0;
}