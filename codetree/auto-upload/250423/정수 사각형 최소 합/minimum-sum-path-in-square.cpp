#include <iostream>
#include <cstdio>
using namespace std;

int n;
int grid[100][100];
int mem[100][100];
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            mem[i][j] = 0x7fff0000;
        }
    }   
    // Please write your code here.
    mem[0][n-1] = grid[0][n-1];
    for(int i=0;i<n;i++)
    {
        for(int j=n-1;j>=0;j--)
        {
            // printf("mem init [%d,%d] : %d\n",i,j,mem[i][j]);
            if(i>0) mem[i][j] = min(mem[i][j],mem[i-1][j]+grid[i][j]);  // 위와 비교
            if(j<n-1) mem[i][j] = min(mem[i][j],mem[i][j+1]+grid[i][j]); // 오른쪽과 비교

            // printf("[%d,%d] : %d\n",i,j,mem[i][j]);
 
        }
    }

    cout << mem[n-1][0];
    return 0;
}
