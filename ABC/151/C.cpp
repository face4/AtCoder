#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<bool> ac(n, 0);
    vector<int> wa(n, 0);
    int g = 0, b = 0;
    while(m--){
        int p;
        string s;
        cin >> p >> s;
        p--;
        if(ac[p])   continue;
        if(s == "WA"){
            wa[p]++;
        }else{
            g++;
            ac[p] = true;
            b += wa[p];
        }
    }
    cout << g << " " << b << endl;
    return 0;
}