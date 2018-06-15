#include<iostream>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    char A[n][n], B[m][m];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> A[i][j];
        }
    }

    for(int i = 0; i < m; i++){
        for(int j = 0; j < m; j++){
            cin >> B[i][j];
        }
    }

    for(int i = 0; i <= n-m; i++){
        for(int j = 0; j <= n-m; j++){
            // check
            bool res = true;
            for(int k = 0; k < m; k++){
                for(int l = 0; l < m; l++){
                    if(B[k][l] != A[i+k][j+l])  res = false;
                }
            }

            if(res){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;
    return 0;
}