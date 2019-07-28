#include<iostream>
using namespace std;

bool ok(int a){
    int i = 1;
    while(i*i < a)  i++;
    return i*i == a;
}

int main(){
    int n, d;
    cin >> n >> d;
    int x[n][d];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < d; j++){
            cin >> x[i][j];
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            int sum = 0;
            for(int k = 0; k < d; k++){
                sum += (x[i][k]-x[j][k])*(x[i][k]-x[j][k]);
            }
            if(ok(sum)) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}