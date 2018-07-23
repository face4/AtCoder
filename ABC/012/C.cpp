#include<iostream>
using namespace std;

int main(){
    int sum = 0;
    for(int i = 1; i <= 9; i++){
        for(int j = 1; j <= 9; j++){
            sum += i*j;
        }
    }

    int n;
    cin >> n;

    int target = sum - n;

    for(int i = 1; i <= 9; i++){
        for(int j = 1; j <= 9; j++){
            if(i*j == target)   cout << i << " x " << j << endl;
        }
    }

    return 0;
}