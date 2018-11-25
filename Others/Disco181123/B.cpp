#include<iostream>
#include<cmath>
using namespace std;

int n;

bool check(double x, double y){
    return (abs(x)+abs(y)) <= (double)n/2;
}

int main(){
    cin >> n;

    int ans = 0;
    if(n%2 == 0){
        for(int i = -n/2; i <= n/2-1; i++){
            for(int j = -n/2; j <= n/2-1; j++){
                if(check(i,j) && check(i+1,j) && check(i,j+1) && check(i+1,j+1))    ans++;
            }
        }
    }else{
        for(int i = -n/2; i <= n/2; i++){
            for(int j = -n/2; j <= n/2; j++){
                if(check(i+0.5,j+0.5) && check(i+0.5,j-0.5) && check(i-0.5,j+0.5) && check(i-0.5,j-0.5))    ans++;
            }
        }
    }

    cout << ans << endl;

    return 0;
}