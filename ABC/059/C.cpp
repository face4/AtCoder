#include<iostream>
using namespace std;

typedef long long ll;

int n;
ll a[100000] = {};

ll solve(bool judge){
    ll sum = 0, score = 0;
    for(int i = 0; i < n; i++){
        sum += a[i];
        if(judge){
            if(sum <= 0){
                score += 1-sum;
                sum = 1;
            }
        }else{
            if(sum >= 0){
                score += sum+1;
                sum = -1;
            }
        }
        judge = !judge;
    }
    return score;
}

int main(){
    cin >> n;

    for(int i = 0; i < n; i++)  cin >> a[i];

    ll first = solve(true);
    ll second = solve(false);

    cout << min(first, second) << endl;

    return 0;
}