#include <iostream>

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

    // Please write your code here.

    mem[0][0] = grid[0][0];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i>0) mem[i][j] = max(mem[i][j], mem[i-1][j] + grid[i][j]);
            if(j>0) mem[i][j] = max(mem[i][j], mem[i][j-1] +grid[i][j]);
        }
    }

    cout << mem[n-1][n-1];
    
    return 0;
}
