#include <bits/stdc++.h>
using namespace std;
int n;
int k;
void printKMax(const vector<int>& a, int k) {
    deque<int> Qi(k);
    for (int i = 0; i < n+k-1; ++i) {
        while (!Qi.empty() && Qi.front() <= i - k) {
            Qi.pop_front();
        }
        while (!Qi.empty() && a[i] >= a[Qi.back()]) {
            Qi.pop_back();
        }
        Qi.push_back(i);
        if(i>=k-1)cout << a[Qi.front()] << " ";
    }
}

int main(){
    vector<int> arr;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
      int num;
      cin >> num;
      arr.push_back(num);
    }
  for(int i = 0; i < n; i++) arr.push_back(arr[i]);
    printKMax(arr, k);
}
