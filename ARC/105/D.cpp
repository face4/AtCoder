#include<iostream>
#include<map>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        map<int,int> m;
        for(int i = 0; i < n; i++){
            int x;  cin >> x;
            m[x]++;
        }
        bool f = true;
        for(auto p : m){
            f &= p.second%2==0;
        }
        if(n%2==1 || (n%2==0&&f))   cout << "Second" << endl;
        else                        cout << "First" << endl;
    }
    return 0;
}