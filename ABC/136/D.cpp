#include<iostream>
#include<vector>
#include<vector>
using namespace std;

int main(){
    string s;
    cin >> s;
    int n = s.length();
    vector<int> l, r;
    for(int i = 0; i < n; i++){
        if(s[i] == 'L') l.push_back(i);
        else            r.push_back(i);
    }
    vector<int> v(n, 0);
    for(int i = 0; i < n; i++){
        if(s[i] == 'L'){
            int j = r[lower_bound(r.begin(),r.end(),i)-r.begin()-1];
            if((i-j)%2) v[j+1]++;
            else        v[j]++;
        }else{
            int j = l[lower_bound(l.begin(),l.end(),i)-l.begin()];
            if((j-i)%2) v[j-1]++;
            else        v[j]++;
        }
    }
    for(int i = 0; i < n; i++)  cout << v[i] << " \n"[i+1==n];
    return 0;
}