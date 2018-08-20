#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int a[3], b[3];
    for(int i = 0; i < 3; i++)  cin >> a[i];
    for(int i = 0; i < 3; i++)  cin >> b[i];
    sort(b, b+3);

    int ans = 0;
    do{
        ans = max(ans, (a[0]/b[0])*(a[1]/b[1])*(a[2]/b[2]));
    }while(next_permutation(b, b+3));

    cout << ans << endl;

    return 0;
}