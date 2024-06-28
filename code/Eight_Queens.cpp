#include <bits/stdc++.h>
using namespace std;
int sol;
#define endl "\n"

// `N × N` 棋盤
//#define N 8
// 檢查兩個皇后是否相互威脅的函數
int isSafe(char mat[][10], int r, int c,int N)
{
    // 如果兩個皇后共享同一列，則返回 0
    for (int i = 0; i < r; i++)
    {
        if (mat[i][c] == 'Q') {
            return 0;
        }
    }

    // 如果兩個皇后共享相同的對角線，則返回 0
    for (int i = r, j = c; i >= 0 && j >= 0; i--, j--)
    {
        if (mat[i][j] == 'Q') {
            return 0;
        }
    }

    // 如果兩個皇后共享相同的 `/` 對角線，則返回 0
    for (int i = r, j = c; i >= 0 && j < N; i--, j++)
    {
        if (mat[i][j] == 'Q') {
            return 0;
        }
    }

    return 1;
}

void printSolution(char mat[][10], int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++) {
            cout<<mat[i][j];
        }
        cout<<endl;
    }
    cout<<endl;
}

void nQueen(char mat[][10], int r,int N)
{
    // 如果 `N` 皇后放置成功，打印解決方案
    if (r == N)
    {
        printSolution(mat,N);
        sol++;
        return;
    }

    // 在當前行的每個方格放置皇后 `r`
    // 並為每個有效動作重複
    for (int i = 0; i < N; i++)
    {
        // 如果沒有兩個皇后互相威脅
        if (isSafe(mat, r, i,N))
        {
            // 將皇后放在當前方格上
            mat[r][i] = 'Q';

            // 重複下一行
            nQueen(mat, r + 1,N);

            // 回溯並從當前方格中移除皇后
            mat[r][i] = 'x';
        }
    }
}

int main()
{
    int N;
    sol=0;
    while(cin>>N){
          if(N==0) break;
    // `mat[][]` 跟踪當前配置中皇后的位置
    char mat[10][10];

    // 用 `-` 初始化 `mat[][]`
    memset(mat, 'x', sizeof mat);

    nQueen(mat, 0,N);
    cout<<endl;
    cout<<sol<<endl;
    sol=0;
    }
    return 0;
}
-----------------------------------------------------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;
int sol;
int N;
int v[3][100];
char mat[10][10];

void nQueen( int r)
{
    if (r == N)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++) {
               cout<<mat[i][j];
            }
            cout<<endl;
        }
        cout<<endl;
        sol++;
        return;
    }
    for (int i = 0; i < N; i++)
    {
        if (!v[0][i] &&!v[1][r+i]&&!v[2][r-i+N])
        {
            mat[r][i] = 'Q';
            v[0][i]=v[1][i+r]=v[2][r-i+N]=1;
            nQueen(r + 1);
            mat[r][i] = 'x';
            v[0][i]=v[1][i+r]=v[2][r-i+N]=0;
        }
    }
}

int main()
{
    sol=0;
    while(cin>>N){
      if(N==0) break;
      char mat[N][N];
      nQueen(0);
      cout<<endl;
      cout<<sol<<endl;
      sol=0;
    }
    return 0;
}
