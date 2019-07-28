#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)  cin >> a[i];
    sort(a.begin(), a.end());

    if(a[n-1] == 0){
        cout << "Yes" << endl;
    }else if(n%3){
        cout << "No" << endl;
    }else{
        int k = n/3;
        if(a[0]==a[k-1]&&a[k]==a[2*k-1]&&a[2*k]==a[3*k-1]&&(a[0]^a[k]^a[2*k])==0)
            cout << "Yes" << endl;
        else 
            cout << "No" << endl;
    }

    return 0;
}