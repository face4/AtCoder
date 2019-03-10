#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;
typedef long long ll;

int main(){
    string s;
    cin >> s;
    int n = s.length();

    vector<int> v;
    int p = 0, m = 0;
    for(int i = n-1; i >= 0; i--){
        if(s[i] == 'M'){
            v.push_back(p-m);
        }else if(s[i] == '+'){
            p++;
        }else if(s[i] == '-'){
            m++;
        }
    }
    sort(v.begin(), v.end());

    cout << accumulate(v.begin()+v.size()/2, v.end(), 0ll)-
            accumulate(v.begin(), v.begin()+v.size()/2, 0ll) << endl;
    
    return 0;
}