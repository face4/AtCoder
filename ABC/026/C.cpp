#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
int payment[21] = {};
int boss[21] = {};
vector<vector<int>> buka(21);

int calc(int josi){
    if(buka[josi].size() == 0)  return 1;

    vector<int> payments;
    for(int i = 0; i < buka[josi].size(); i++){
        if(payment[buka[josi][i]] == 0){
            payment[buka[josi][i]] = calc(buka[josi][i]);
        }
        payments.push_back(payment[buka[josi][i]]);
    }

    sort(payments.begin(), payments.end());
    return payments[0] + payments[payments.size()-1] + 1;
}

int main(){
    cin >> n;

    for(int i = 2; i <= n; i++){
        cin >> boss[i];
        buka[boss[i]].push_back(i);
    } 

    cout << calc(1) << endl;
}