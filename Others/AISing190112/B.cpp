#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int n, a, b;
    cin >> n >> a >> b;

    int cnt[3] = {};
    int p;
    for(int i = 0; i < n; i++){
        cin >> p;
        if(p <= a)  cnt[0]++;
        else if(p > b)  cnt[2]++;
        else            cnt[1]++;
    }

    cout << *min_element(cnt, cnt+3) << endl;

    return 0;
}