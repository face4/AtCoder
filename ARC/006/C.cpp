#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> ans;
    for(int i = 0; i < n; i++){
        int w;
        cin >> w;
        vector<int>::iterator it = lower_bound(ans.begin(), ans.end(), w);
        if(it == ans.end()){
            ans.push_back(w);
        }else{
            *it = w;
        }
        sort(ans.begin(), ans.end());
    }

    cout << ans.size() << endl;

    return 0;
}