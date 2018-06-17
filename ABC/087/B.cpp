#include<iostream>
using namespace std;

int main(){
    int a, b, c, x;
    cin >> a >> b >> c >> x;

    x /= 50;

    int cnt = 0;
    for(int i = 0; i <= a; i++){
        for(int j = 0; j <= b; j++){
            if(10*i+2*j <= x && x-10*i-2*j <= c)    cnt++;
        }
    }

    cout << cnt << endl;
    return 0;
}