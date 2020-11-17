#include<iostream>
using namespace std;

int main(){
    int a[4], sum = 0;
    for(int i = 0; i < 4; i++)  cin >> a[i], sum += a[i];
    for(int i = 1; i < 1<<4; i++){
        int take = 0;
        for(int j = 0; j < 4; j++)  if(i>>j&1)  take += a[j];
        if(2*take == sum){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}