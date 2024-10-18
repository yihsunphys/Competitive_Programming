#include <bits/stdc++.h>
using namespace std;
    int n;
    int k;
void printKMax(const vector<int>& a, int k) {
    deque<int> Qi(k);
    int i;
    for (i = 0; i < k; ++i) {
        while (!Qi.empty() && a[i] >= a[Qi.back()]) {
            Qi.pop_back();
        }
        Qi.push_back(i);
    }
    for (; i < n+k-1; ++i) {
        cout << a[Qi.front()] << " ";
        while (!Qi.empty() && Qi.front() <= i - k) {
            Qi.pop_front();
        }
        while (!Qi.empty() && a[i] >= a[Qi.back()]) {
            Qi.pop_back();
        }
        Qi.push_back(i);
    }
    cout << a[Qi.front()];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
  cout.tie(0); 
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
