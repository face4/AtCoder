#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            int k = i^j, cnt = 1;
            while(k%2 == 0){
                cnt++, k/=2;
            }
            cout << cnt << " \n"[j+1==n];
        }
    }
    return 0;
}