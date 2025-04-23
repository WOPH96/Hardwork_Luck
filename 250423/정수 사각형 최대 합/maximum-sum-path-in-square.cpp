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
            if(i== n-1 && j==n-1) break;
            mem[i+1][j] = max(mem[i+1][j],mem[i][j]+grid[i+1][j]);
            mem[i][j+1] = max(mem[i][j+1],mem[i][j]+grid[i][j+1]);
        }
    }

    cout << mem[n-1][n-1];
    
    return 0;
}
