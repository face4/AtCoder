#include<iostream>
#include<set>
using namespace std;

int main(){
    int n;
    string before, now;
    set<string> used;
    
    cin >> n;
    cin >> before;
    used.insert(before);

    bool judge = true;
    for(int i = 1; i < n; i++){
        cin >> now;
        if(used.count(now) || before[before.length()-1] != now[0]){
            judge = false;
        }
        used.insert(now);
        before = now;
    }

    if(judge)   cout << "Yes" << endl;
    else        cout << "No" << endl;

    return 0;
}