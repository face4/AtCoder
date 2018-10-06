#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

struct data{
    int a, b;
    data(int a, int b) : a(a), b(b) {}
    data() {}    
    bool operator< (const data other) const{
        return b > other.b;
    }
};

int main(){
    int n;
    cin >> n;

    int a[n];
    for(int i = 0; i < n; i++)  cin >> a[i];

    bool allsame = true;
    for(int i = 1; i < n; i++)  if(a[i-1] != a[i])  allsame = false;

    if(allsame){
        cout << n/2 << endl;
        return 0;
    }
    
    map<int,int> x, y;
    for(int i = 0; i < n; i++){
        if(i%2 == 0)    x[a[i]]++;
        if(i%2 == 1)    y[a[i]]++;
    }

    vector<data> s, t;
    for(auto p : x) s.push_back(data(p.first, p.second));
    for(auto p : y) t.push_back(data(p.first, p.second));

    sort(s.begin(), s.end());
    sort(t.begin(), t.end());

    int ans = n;
    for(data p : s){
        for(data q : t){
            if(p.a != q.a){
                ans = min(ans, n/2-p.b + n/2-q.b);
                break;
            }
        }
    }

    cout << ans << endl;
    return 0;
}