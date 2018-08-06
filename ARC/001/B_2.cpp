#include<iostream>
using namespace std;

int x[10] = {0, 1, 2, 3, 2, 1, 2, 3, 3, 2};

int main(){
    int a, b;
    cin >> a >> b;
    cout << abs(a-b)/10 + x[abs(a-b)%10] << endl;
    return 0;
}