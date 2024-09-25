#include <chrono>
#include <bits/stdc++.h>
using namespace std;
double speed(int iter_num) {
const int block_size = 1024;
volatile int A[block_size];
auto begin = chrono::high_resolution_clock::now();
while (iter_num--)
for (int j = 0; j < block_size; ++j)
A[j] += j;
auto end = chrono::high_resolution_clock::now();
chrono::duration<double> diff = end - begin;
return diff.count();
}

size_t block_size, bound;
void stack_size_dfs(size_t depth = 1) {
  if (depth >= bound)
    return;
  int8_t ptr[block_size]; // 若無法編譯將 block_size 改成常數
  memset(ptr, 'a', block_size);
  cout << depth << endl;
  stack_size_dfs(depth + 1);
}
void stack_size_and_runtime_error(size_t block_size, size_t bound = 1024) {
  ::block_size = block_size;
  ::bound = bound;
  stack_size_dfs();
}


int main(){
  //std::cout << speed(1024*1024);
  stack_size_and_runtime_error(1024*1024);
  return 0;
}
