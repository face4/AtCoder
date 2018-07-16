#include<iostream>
using namespace std;

int main(){
    int n, a;
    cin >> n;

    int two = 0, four = 0, odd = 0;
    
    for(int i = 0; i < n; i++){
        cin >> a;

        if(a%4 == 0)        four++;
        else if(a%2 == 0)   two++;
        else                odd++;
    }

    if(odd == 0 || four >= odd || (four+1 == odd && two == 0)){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

    return 0;
}