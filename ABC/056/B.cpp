#include<iostream>
using namespace std;

int main(){
    int w, a, b;
    cin >> w >> a >> b;

    int res;
    if(b > a+w)         res = b-a-w;
    else if(b + w < a)  res = a-b-w;
    else                res = 0;

    cout << res << endl;
    return 0;
}