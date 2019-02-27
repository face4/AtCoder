#include<iostream>
#include<vector>
#include<iomanip>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)  cin >> v[i];
    sort(v.begin(), v.end());
    double ans = 0;
    for(int i = 0; i < n; i++){
        int cnt = 0;
        for(int j = 0; j < n; j++)  if(i != j && v[i]%v[j]==0)    cnt++;
        int tmp = (cnt+2)/2;
        ans += (double)(tmp) / (cnt+1);
    }
    cout << fixed << setprecision(12) << ans << endl;
    return 0;
}