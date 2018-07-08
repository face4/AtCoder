#include<iostream>
using namespace std;

int main(){
    int t, n, m;
    cin >> t >> n;
    
    int A[n];
    for(int i = 0; i < n; i++)  cin >> A[i];
    
    cin >> m;
    int B[m];
    for(int i = 0; i < m; i++)  cin >> B[i];

    int tako = 0, cust = 0;
    while(tako < n && cust < m){
        if(A[tako] <= B[cust] && B[cust] <= A[tako]+t){
            tako++;
            cust++;
        }else{
            tako++;
        }
    }

    if(cust == m)   cout << "yes" << endl;
    else            cout << "no" << endl;

    return 0;
}