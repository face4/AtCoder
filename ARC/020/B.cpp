#include<iostream>
using namespace std;

int main(){
    int n, c, a, odd[11] = {}, even[11] = {};
    cin >> n >> c;

    for(int i = 0; i < n; i++){
        cin >> a;
        if(i%2 == 0)    odd[a]++;
        else            even[a]++;
    }

    int ans = n;
    for(int i = 1; i <= 10; i++){
        for(int j = 1; j <= 10; j++){
            if(i == j)  continue;
            ans = min(ans, (n+1)/2-odd[i] + n/2-even[j]);
            ans = min(ans, (n+1)/2-odd[j] + n/2-even[i]);
        }
    }

    cout << ans*c << endl;

    return 0;
}