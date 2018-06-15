#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin >> n;

    if(n < 6){
        cout << n << endl;
        return 0;
    }

    bool dp[n+1] = {}; // default false
    dp[0] = true;

    vector<int> six;
    vector<int> nine;

    int si = 1;
    while(n >= si*6){
        si*=6;
        six.push_back(si);
    }

    int ni = 1;
    while(n >= ni*9){
        ni *= 9;
        nine.push_back(ni);
    }


    int ans = 0;
    while(!dp[n]){
        ans++;
        for(int i = n; i >= 0; i--){
            if(dp[i]){
                dp[i+1] = true;
                for(auto p : six){
                    if(i+p <= n)    dp[i+p] = true;
                }

                for(auto p : nine){
                    if(i+p <= n)    dp[i+p] = true;
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}