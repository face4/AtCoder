#include<iostream>
using namespace std;

int main(){
    int y, m, d;
    scanf("%d/%d/%d", &y, &m, &d);
    if(10000*y+100*m+d <= 20190430)  cout << "Heisei" << endl;
    else                            cout << "TBD" << endl;
    return 0;
}