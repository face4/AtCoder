#include<iostream>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b){
    return (b == 0) ? a : gcd(b, a%b);
}

int main(){
    int t;
    cin >> t;

    while(t-- > 0){
        ll a, b, c, d;
        cin >> a >> b >> c >> d;

        if(a < b || b > d){
            cout << "No" << endl;
            continue;
        }

        if(b <= c+1){
            cout << "Yes" << endl;
            continue;
        }

        ll g = gcd(b,d);
        // there exists an integer t s.t. c < (a-b + t*g) < b ?

        ll first = a-b;

        if(first > c){
            first -= (first-c)/g * g;
        }else if(first < c){
            first += (c-first)/g * g;
            if(first < c)   first += g;
        }

        bool found = false;
        while(1){
            if(c < first && first < b){
                found = true;
                break;
            }else if(first >= b){
                break;
            }else{
                first += g;
            }
        }

        if(found)   cout << "No" << endl;
        else        cout << "Yes" << endl;
    }

    return 0;
}