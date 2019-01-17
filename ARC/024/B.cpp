#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    int a[n];
    for(int i = 0; i < n; i++)  cin >> a[i];

    int len = 1;
    for(int i = 0; i < n; i++){
        int tmp = 1;
        while(a[(i+1)%n] == a[i%n]){
            i++;
            tmp++;
            if(tmp > n){
                cout << "-1" << endl;
                return 0;
            }
        }
        len = max(len, tmp);
    }

    cout << 1+(len-1)/2 << endl;

    return 0;
}