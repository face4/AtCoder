#include<iostream>
#include<climits>
using namespace std;

int main(){
	int n;
	cin >> n;
	
	int x;
	int f[n][10];
	int p[n][11];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 10; j++){
			cin >> f[i][j];
		}
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 11; j++){
			cin >> p[i][j];
		}
	}
	
	int ans = INT_MIN;
	for(int i = 1; i < (1<<10); i++){
		int tmp = 0;
		for(int j = 0; j < n; j++){
			int cover = 0;
			for(int k = 0; k < 10; k++){
				if(((1<<k) & i) && f[j][k] == 1)	cover++;
			}
			tmp += p[j][cover];
		}
		ans = max(ans, tmp);
	}
	
	cout << ans << endl;
	
	return 0;
}
