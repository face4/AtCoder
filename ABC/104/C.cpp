#include<iostream>
#include<climits>
using namespace std;

int main(){
    int d, g;
    cin >> d >> g;

    int p[d], c[d];
    for(int i = 0; i < d; i++)  cin >> p[i] >> c[i];

    int ans = INT_MAX;
    for(int i = 0; i < 1<<d; i++){
        int score = 0, _max, count = 0;
        for(int j = 0; j < d; j++){
            if(i & (1<<j))  score += p[j] * (j+1) * 100 + c[j], count += p[j];
            else            _max = j;
        }

        if(score >= g)  
            ans = min(ans, count);
        else if(g-score <= p[_max] * (_max+1) * 100)
            ans = min(ans, count + (g-score+(_max+1)*100-1) / ((_max+1)*100) );
        else
            continue;
    }

    cout << ans << endl;

    return 0;
}