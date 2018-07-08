#include<iostream>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    int A, B, C;
    bool found = false;
    for(B = 0; B < n && m-3*B >= 0; B++){
        if((m-3*B)%2 != 0)  continue;
        int D = (m-3*B)/2;
        int E = n-B;
        C = D-E;
        A = E-C;
        if(A >= 0 && B >= 0 && C >= 0){
            found = true;
            break;
        }
    }

    if(!found)  A = B = C = -1;

    printf("%d %d %d\n", A, B, C);
    
    return 0;
}