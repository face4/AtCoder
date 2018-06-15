#include<iostream>
using namespace std;

int main(){
    int x, y;
    cin >> x >> y;

    int group[13] = {-1,0,1,0,2,0,2,0,0,2,0,2,0};

    if(group[x]==group[y])  cout << "Yes" << endl;
    else                    cout << "No" << endl;
}