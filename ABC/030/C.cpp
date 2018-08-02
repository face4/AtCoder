#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n, m, x, y, in;
    cin >> n >> m >> x >> y;

    vector<int> atob, btoa;
    for(int i = 0; i < n; i++){
        cin >> in;
        atob.push_back(in);
    }

    for(int i = 0; i < m; i++){
        cin >> in;
        btoa.push_back(in);
    }

    int aindex = 0, bindex = 0, now = 0;
    int ans = 0; bool atA = true;

    while(aindex < n && bindex < m){
        if(atA){
            while(aindex < n && now > atob[aindex])   aindex++;
            if(aindex < n){
                atA = false;
                now = atob[aindex] + x;
            }else{
                break;
            }
        }else{
            while(bindex < m && now > btoa[bindex]) bindex++;
            if(bindex < m){
                atA = true;
                now = btoa[bindex] + y;
                ans++;
            }else{
                break;
            }
        }
    }

    cout << ans << endl;
    
    return 0;
}