#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    if(n%2) cout << (n-1)*(n-1)/2 << endl;
    else    cout << (n-2)*n/2 << endl;
    int sum = n%2 == 1 ? n : n+1;
    for(int i = 1; i < n/2*2; i++){
        for(int j = i+1; j <= n/2*2; j++){
            if(i+j != sum)  cout << i << " " << j << endl;
        }
    }
    if(n%2) for(int j = 1; j < n; j++)  cout << n << " " << j << endl;
    return 0;
}