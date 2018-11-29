#include<iostream>
#include<iomanip>
#include<numeric>
#include<cfloat>
using namespace std;

int main(){
  int n;
  cin >> n;

  int t[n+2];
  double v[n+2];
  t[0] = t[n+1] = v[0] = v[n+1] = 0;

  for(int i = 1; i <= n; i++) cin >> t[i];
  for(int i = 1; i <= n; i++) cin >> v[i];

  double answer = 0.0;
  
  for(double a = 0.0; a < accumulate(t, t+n+2, 0); a+=0.5){
    double va = DBL_MAX, vb = DBL_MAX;
    int now = 0;
    for(int i = 0; i < n+2; i++){
      double tmpva, tmpvb;
      if(a < now)            tmpva = (now-a) + v[i];
      else if(a > now+t[i])  tmpva = (a-(now+t[i])) + v[i];
      else                   tmpva = v[i];
      if(a+0.5 < now)            tmpvb = (now-(a+0.5)) + v[i];
      else if(a+0.5 > now+t[i])  tmpvb = (a+0.5-(now+t[i])) + v[i];
      else                       tmpvb = v[i];
      va = min(va, tmpva);
      vb = min(vb, tmpvb);
      now += t[i];
    }
    answer += (va + vb) * 0.5 / 2;
  }

  cout << fixed << setprecision(10) << answer << endl;
  
  return 0;
}
