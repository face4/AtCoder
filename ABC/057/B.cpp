#include<iostream>
#include<climits>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    int a[n], b[n], c[m], d[m];
    
    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
    }

    for(int i = 0; i < m; i++){
        cin >> c[i] >> d[i];
    }

    for(int i = 0; i < n; i++){
        int mindis = INT_MAX;
        int ans;

        for(int j = 0; j < m; j++){
            int tmp = abs(c[j]-a[i]) + abs(d[j]-b[i]);
            if(mindis > tmp){
                mindis = tmp;
                ans = j;
            }
        }

        cout << ans+1 << endl;
    }

    return 0;
}