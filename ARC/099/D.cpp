#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int k;
    cin >> k;

    if(k < 10){
        for(int i = 1; i <= k; i++) cout << i << endl;
    }else if(k <= 18){
        for(int i = 1; i <= 9; i++)     cout << i << endl;
        for(int i = 1; i <= k-9; i++)   cout << i << "9" << endl;
    }else{
        for(int i = 1; i <= 9; i++)     cout << i << endl;
        for(int i = 1; i <= 9; i++)   cout << i << "9" << endl;
        
        int top = 19;
        int ninenum = 1;
        for(int i = 18; i < k; i++){
            printf("%d", top);
            for(int j = 0; j < ninenum; j++)    printf("9");
            printf("\n");

            if(top == 99){
                top = 10;
                ninenum++;
            }else if(top == 10*ninenum){
                top += 9;
            }else if(top+1 >= min(100,10*ninenum)){
                top += 10;    
            }else{
                top++;
            }
        }
    }
    

}