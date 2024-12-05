#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n, k;
string str;
#define ROBOT 'P'
#define ITEM 'H'

void sol()
{
    int cnt = 0;
    vector<int> alive(n, 1);
    for (int i = 0; i < n; i++)
    {
        if (str[i] == ROBOT)
        {
            for (int j = -k; j <= k; j++)
            {
                if (i + j >= 0 && i + j < n &&
                    str[i + j] == ITEM &&
                    alive[i + j])
                {
                    alive[i + j] = 0;
                    cnt++;
                    // for(auto &elem : str){
                    //     cout << elem << " ";
                    // }
                    // cout << endl;
                    // for(auto &elem : alive){
                    //     cout << elem  << " ";
                    // }
                    // cout << endl;
                    break;
                }
            }
        }
    }
    cout << cnt << endl;
}

void input()
{
    cin >> n >> k;
    cin.ignore();
    cin >> str;
}

int main(int argc, char **argv)
{
    input();
    sol();
    return 0;
}