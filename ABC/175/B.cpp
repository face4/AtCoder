#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int l[n];
    for(int i = 0; i < n; i++)  cin >> l[i];
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(l[i] == l[j])    continue;
            for(int k = j+1; k < n; k++){
                if(l[k]==l[i] || l[k]==l[j])    continue;
                ans += (l[i]+l[j]>l[k]&&l[k]+l[j]>l[i]&&l[i]+l[k]>l[j]);
            }
        }
    }
    cout << ans << endl;
    return 0;
}