#include<iostream>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;

    ll a[n][n], sum = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
            if(i < j)   sum += a[i][j];
        }
    }

    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(a[i][j] > a[i][k]+a[k][j]){
                    cout << "-1" << endl;
                    return 0;
                }
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            bool need = true;
            for(int k = 0; k < n; k++){
                if(i == k || j == k)    continue;
                if(a[i][k]+a[k][j] == a[i][j])  need = false;
            }
            if(!need)   sum -= a[i][j];
        }
    }

    cout << sum << endl;

    return 0;
}