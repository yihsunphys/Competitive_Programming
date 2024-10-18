#include <bits/stdc++.h>
using namespace std;

int a, b, c, d;
int M, S, T;
int dist = 0;

int main() {
  cin >> a >> b >> c >> d;
  cin >> M >> S >> T;
  int t = 0;
  while(t < T) {
    if(dist >= S) {
      cout << "Yes\n" << t << endl;
      return 0;
    }
    if(M >= c) {
      M -= c;
      t++;
      dist += b;
    }
    else {
      int timetoreboot = ceil(double(c-M)/d);//cout << "NOW:" << t << " " << timetoreboot << "dist" << dist << '\n';
      if((t + timetoreboot + 1) >T){
        dist += a;
        t++;
      }
      else if(dist + a*(timetoreboot+1) >= S) {
        dist += a;
        t++; 
      }
      else if(a*(timetoreboot+1) >= b) {
        dist += a;
        t++; 
      }
      else {
        t += timetoreboot;
        M += d*timetoreboot;
      }
    }
  }
  if(dist >= S) cout << "Yes\n" << t << endl;
  else cout << "No\n" << dist << endl;
}