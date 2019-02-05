#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;

    int l[n];
    for(int i = 0; i < n; i++)  cin >> l[i];
    sort(l, l+n);

    int sum = 0;
    for(int i = 0; i < n-1; i++)    sum += l[i];

    if(l[n-1] < sum)    cout << "Yes" << endl;
    else                cout << "No" << endl;
    
    return 0;
}