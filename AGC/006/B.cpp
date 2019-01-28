#include<iostream>
#include<deque>
using namespace std;

int main(){
    int n, x;
    cin >> n >> x;

    if(x == 1 || x == 2*n-1){
        cout << "No" << endl;
        return 0;
    }

    if(n == 2){
        if(x == 2){
            cout << "Yes" << endl << 1 << endl << 2 << endl << 3 << endl;
        }else{
            cout << "No" << endl;
        }
        return 0;
    }

    cout << "Yes" << endl;

    deque<int> ans;

    if(x != 2*n-1-1){
        ans.push_back(x);
        ans.push_front(x-1);
        ans.push_back(x+1);
        ans.push_front(x+2);
        int now = 1;
        for(int i = 0; i < n-3; i++){
            if(now == x-1)  now = x+3;
            ans.push_front(now++);
        }
        for(int i = 0; i < n-2; i++){
            if(now == x-1)  now = x+3;
            ans.push_back(now++);
        }
    }else{
        ans.push_back(x);
        ans.push_front(x-1);
        ans.push_back(x+1);
        ans.push_back(x-2);
        int now = 1;
        for(int i = 0; i < n-2; i++){
            if(now == x-2)  now = x+2;
            ans.push_front(now++);
        }
        for(int i = 0; i < n-3; i++){
            if(now == x-2)  now = x+2;
            ans.push_back(now++);
        }
    }

    while(!ans.empty()){
        cout << ans.front() << endl;
        ans.pop_front();
    }

    return 0;
}