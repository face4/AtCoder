#include<iostream>
using namespace std;

int main(){
    int ans = 0;
    for(int i = 0; i < 1<<10; i++){
        ans ^= i;
    }
    return 0;
}