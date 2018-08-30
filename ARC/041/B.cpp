#include<iostream>
using namespace std;

int b[500][500] = {}, a[500][500] = {};
int dx[4] = {-1,0,0,1};
int dy[4] = {0,-1,1,0};

int main(){
    int n, m;
    cin >> n >> m;

    char x;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> x;
            b[i][j] = x-'0';
        }
    }

    for(int i = 1; i < n-1; i++){
        for(int j = 1; j < m-1; j++){
            if(b[i-1][j]){
                int dec = 10;
                for(int k = 0; k < 4; k++){
                    dec = min(dec, b[i+dx[k]][j+dy[k]]);
                }
                a[i][j] = dec;
                for(int k = 0; k < 4; k++){
                    b[i+dx[k]][j+dy[k]] -= dec;
                }
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << a[i][j];
        }
        cout << endl;
    }

    return 0;
}