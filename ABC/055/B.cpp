#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    long long power = 1;
    
    for(long long  i = 1; i <= n; i++){
        power = (power*i) % 1000000007;
    }
    
    cout << power << endl;

    return 0;
}