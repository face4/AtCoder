#include<iostream>
using namespace std;

int main(){
    int r, c, d, a;
    scanf("%d %d %d", &r, &c, &d);

    int ans = 0;

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            scanf("%d", &a);
            if(i+j <= d && (d-i-j)%2 == 0)  ans = max(ans, a);
        }
    }

    cout << ans << endl;
    return 0;
}