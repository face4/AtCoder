#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;

    char x;
    int a[4];
    for(int i = 0; i < 4; i++)  a[i] = 0;
    for(int i = 0; i < n; i++){
        cin >> x;
        a[x-'0'-1]++;
    }
    sort(a, a+4);

    cout << a[3] << " " << a[0] << endl;
    
    return 0;
}