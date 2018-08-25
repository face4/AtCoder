#include<iostream>
using namespace std;

int pastdays(int y, int m, int d){
    if(m <= 2)  y--, m += 12;
    return 365*y + y/4 - y/100 + y/400 + (306*(m+1))/10 + d - 429;
}

int main(){
    int y, m, d;
    cin >> y >> m >> d;
    cout << pastdays(2014,5,17) - pastdays(y,m,d) << endl;
    return 0;
}