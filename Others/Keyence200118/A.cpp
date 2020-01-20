#include<iostream>
using namespace std;

int main(){
    int h, w, n;
    cin >> h >> w >> n;
    if(h > w)   swap(h, w);
    cout << (n+w-1)/w << endl;
    return 0;
}