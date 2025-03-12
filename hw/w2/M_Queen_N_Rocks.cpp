#include <iostream>
#include <stdint.h>
#include <cstring>
#define LSB(n) ((n) & -(n))
#define ll long long
using namespace std;

int nqmc(int queens, int castles, int casleft, int casright,
         int left, int right, int qnum, int cnum,
         int n, int m, int total, int full_columns) {
    int count = 0;
    if (qnum == n && cnum == m) {
        return 1;
    }
    int valid_columns = (~(queens | castles | left | right)) & full_columns;
    for (int col = LSB(valid_columns); col; valid_columns ^= col, col = LSB(valid_columns)) {
        if (qnum < n && (col & casleft) == 0 && (  col & casright) == 0)  {
          count += nqmc(queens | col, castles, casleft << 1, casright >> 1,
        (left | col) << 1, (right | col) >> 1, qnum + 1, cnum, n, m, total, full_columns);
        }
        if (cnum < m) {
            count += nqmc(queens, castles | col, (casleft |col) << 1, (casright |col) >> 1,
            left << 1, right >> 1, qnum, cnum + 1, n, m, total, full_columns);
        }
    }
    return count;
}

int main() {
    int T;
    cin >> T;  
    while (T--) {
      int n, m;
      cin >> n >> m;  
      int total = n + m; 
      ll full_columns = (1 << total) - 1;  
      int solutions = nqmc(0, 0, 0, 0, 0, 0, 0, 0, n, m, total, full_columns);
      cout << solutions << endl;
    }
}
