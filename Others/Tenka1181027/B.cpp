#include<iostream>
using namespace std;

int main(){
    int a[2], k;
    cin >> a[0] >> a[1] >> k;

    for(int i = 0; i < k; i++){
        if(a[i%2] % 2 == 1) a[i%2]--;
        a[1-i%2] += a[i%2]/2;
        a[i%2] /= 2;
    }

    cout << a[0] << " " << a[1] << endl;

    return 0;
}