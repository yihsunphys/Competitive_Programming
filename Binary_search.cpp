#include <bits/stdc++.h>
using namespace std;

int my_upper_bound(int *a, int l, int r, int key) { //大於key的最小值
  while(l <= r) {
    int mid = (l+r)>>1;
    if(a[mid]>key) r = mid-1;
    else l = mid+1;
  }
  return l;
}

int my_lower_bound(int *a, int l, int r, int key) { //大於等於key的最小值
  while(l <= r) {
    int mid = (l+r)>>1;
    if(a[mid]>=key) r = mid-1;
    else l = mid+1;
  }
  return l;
}

int my_binary_search(int *a, int l, int r, int key) { //大於等於key的最小值
  while(l <= r) {
    int mid = (l+r)>>1;
    if(a[mid]>key) r = mid-1;
    else if(a[mid]<key)l = mid+1;
    else return mid;
  }
  return -1;
}

int main() {
  int a[5] = {1, 2, 3, 4, 5};
  cout << my_lower_bound(a, 0, 5, 3);
}