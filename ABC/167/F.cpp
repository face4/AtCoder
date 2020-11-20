#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef pair<int,int> pii;

void ng(){
    cout << "No" << endl;
    exit(0);
}

int main(){
    int n;
    cin >> n;
    vector<pii> a, b, c, d;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        int peek = 0, sum = 0;
        for(char c : s){
            sum += c=='(' ? 1 : -1;
            peek = min(peek, sum);
        }
        if(sum >= 0){
            if(peek >= 0)   a.push_back({sum,peek});
            else            b.push_back({-peek,-sum});
        }else{
            if(peek < 0)    c.push_back({peek,-sum});
            else            d.push_back({sum,peek});
        }
    }
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());
    int sum = 0;
    for(pii p : a){
        sum += p.first;
    }
    for(pii p : b){
        if(sum - p.first < 0)   ng();
        sum += -p.second;
    }
    for(pii p : c){
        if(sum + p.first < 0)   ng();
        sum -= p.second;
    }
    for(pii p : d){
        sum += p.first;
    }
    if(sum != 0)    ng();
    cout << "Yes" << endl;
    return 0;
}
