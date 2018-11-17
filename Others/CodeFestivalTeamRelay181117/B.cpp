#include<iostream>
using namespace std;

int main(){
    string s;
    cin >> s;

    int x, y;
    cin >> x >> y;

    x = abs(x), y = abs(y);
    int a[4] = {};

    if(x > y)   swap(x,y);
    bool judge = (x == 0) && (y == 0);

    for(char c : s){
        if(c == 'W')    a[0]++;
        if(c == 'X')    a[1]++;
        if(c == 'Y')    a[2]++;
        if(c == 'Z')    a[3]++;

        for(int i = 1; i < 4; i++){
            int s = a[0]-a[i];
            int t = 0;
            bool first = true;
            for(int j = 1; j < 4; j++){
                if(i == j)  continue;
                if(first)   t += a[j], first = false;
                else        t -= a[j];
            }
            
            s = abs(s), t = abs(t);
            if(s > t)   swap(s,t);
            if(x == s && t == y)    judge = true;
        }
    }

    if(judge)   cout << "Yes" << endl;
    else        cout << "No" << endl;

    return 0;
}