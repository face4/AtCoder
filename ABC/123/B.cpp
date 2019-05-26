#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    vector<int> d(5);
    for(int i = 0; i < 5; i++)  cin >> d[i];
    sort(d.begin(), d.end());

    int ans = 1<<30;
    do{
        int tmp = 0;
        for(int i = 0; i < 5; i++){
            tmp += d[i];
            if(i != 4)  tmp = (tmp+9)/10 * 10;
        }
        ans = min(ans, tmp);
    }while(next_permutation(d.begin(), d.end()));
    
    cout << ans << endl;
    
    return 0;
}