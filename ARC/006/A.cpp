#include<iostream>
using namespace std;

int main(){
    bool e[10] = {} , b[10] = {};
    int x;

    for(int i = 0; i < 6; i++){
        cin >> x;
        e[x] = true;
    }

    cin >> x;
    b[x] = true;

    int normal = 0, bonus = 0;
    for(int i = 0; i < 6; i++){
        cin >> x;
        if(e[x])    normal++;
        if(b[x])    bonus++;
    }

    if(normal == 6)             cout << 1 << endl;
    else if(normal+bonus == 6)  cout << 2 << endl;
    else if(normal == 5)        cout << 3 << endl;
    else if(normal == 4)        cout << 4 << endl;
    else if(normal == 3)        cout << 5 << endl;
    else                        cout << 0 << endl;

    return 0;
}