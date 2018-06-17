#include<iostream>
using namespace std;

int digitsum(int x){
    int ret = 0;
    while(x > 0){
        ret += x%10;
        x /= 10;
    }
    return ret;
}

int main(){
    int n, a, b;
    cin >> n >> a >> b;

    int sum = 0;
    for(int i = 1; i <= n; i++){
        int tmp = digitsum(i);
        if(a <= tmp && tmp <= b)    sum += i;
    }

    cout << sum << endl;
    return 0;
}