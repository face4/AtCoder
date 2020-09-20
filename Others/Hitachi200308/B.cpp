#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int a, b, m;
    cin >> a >> b >> m;
    vector<int> A(a), B(b);
    for(int i = 0; i < a; i++)  cin >> A[i];
    for(int i = 0; i < b; i++)  cin >> B[i];
    int tmp = *min_element(A.begin(),A.end()) + *min_element(B.begin(),B.end());
    while(m--){
        int x, y, c;
        cin >> x >> y >> c;
        x--, y--;
        tmp = min(tmp, A[x]+B[y]-c);
    }
    cout << tmp << endl;
    return 0;
}