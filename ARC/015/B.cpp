#include<iostream>
using namespace std;

int main(){
    int ans[6] = {};
    int n;
    double lower, upper;

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> upper >> lower;
        if(upper >= 35.0)         ans[0]++;
        else if(upper >= 30.0)    ans[1]++;
        else if(upper >= 25.0)    ans[2]++;

        if(lower >= 25.0)         ans[3]++;
        if(lower < 0.0 && upper >= 0.0) ans[4]++;
        if(upper < 0.0)           ans[5]++;
    }

    for(int i = 0; i < 6; i++)  cout << ans[i] << " \n"[i == 5];

    return 0;
}