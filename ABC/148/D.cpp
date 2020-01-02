#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int now = 1, br = 0;
    for(int i = 0; i < n; i++){
        int x;  cin >> x;
        if(now == x){
            now++;
        }else{
            br++;
        }
    }
    cout << (br == n ? -1 : br) << endl;
    return 0;
}