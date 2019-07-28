#include<iostream>
#include<queue>
using namespace std;

int main(){
    int n;
    cin >> n;

    int cnt[200001] = {};
    int a[n];
    int ma = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        cnt[a[i]]++;
        ma = max(ma, a[i]);
    }

    for(int i = 0; i < n; i++){
        cnt[a[i]]--;
        if(ma == a[i] && cnt[a[i]] == 0){
            for(int j = a[i];;j--){
                if(cnt[j] > 0){
                    cout << j << endl;
                    break;
                }
            }
        }else{
            cout << ma << endl;
        }
        cnt[a[i]]++;
    }

    return 0;
}