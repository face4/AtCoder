#include<iostream>
#include<set>
using namespace std;

#define N 100005

bool taste[N] = {};

int main(){
    int n;
    cin >> n;

    int A[n];
    for(int i = 0; i < n; i++)  cin >> A[i];

    int ans = 0;

    int l = 0, r = 0;
    while(1){
        while(r < n && !taste[A[r]]){
            taste[A[r]] = true;
            r++;
        }

        ans = max(ans, r-l);

        if(r == n)  break;

        while(taste[A[r]]){
            taste[A[l]] = false;
            l++;
        }
    }

    cout << ans << endl;
    return 0;
}