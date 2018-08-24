#include<iostream>
#include<set>
using namespace std;

int main(){
    int n;
    cin >> n;

    string before;
    cin >> before;

    set<string> used;
    used.insert(before);

    int judge = 0;

    for(int i = 1; i < n; i++){
        string next;
        cin >> next;

        if(used.count(next) != 0 || before[before.length()-1] != next[0]){
            if(i%2 == 0)    judge = 1;
            else            judge = -1;
            break;
        }
        
        used.insert(next);
        before = next;
    }

    if(judge == -1) cout << "WIN" << endl;
    if(judge == 0)  cout << "DRAW" << endl;
    if(judge == 1)  cout << "LOSE" << endl;

    return 0;
}