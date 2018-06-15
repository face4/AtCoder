#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int A[3];
    for(int i = 0; i < 3; i++)  cin >> A[i];
    sort(A, A+3);

    if(A[0] == 5 && A[1] == 5 && A[2] == 7) cout << "YES" << endl;
    else                                    cout << "NO" << endl;
    return 0;
}