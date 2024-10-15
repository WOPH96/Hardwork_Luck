#include <iostream>
#include <vector>

using namespace std;

void print();

int n, m;
int person = 0;
int graph[101][101] = {0};
vector<pair<int, int>> attacks;

void input()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> graph[i][j];
            if (graph[i][j] == 1)
            {
                person++;
            }
        }
    }
    for (int i = 0; i < 2; i++)
    {
        int start, end;
        cin >> start >> end;
        attacks.push_back({start, end});
    }
}
void sol()
{
    for (auto &atk : attacks)
    {
        for (int i = atk.first - 1; i < atk.second; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (graph[i][j] == 1)
                {
                    graph[i][j] = 0;
                    person--;
                    break;
                }
            }
        }
    }
}

int main(int argc, char **argv)
{
    input();
    sol();
    print();
    return 0;
}

void print()
{
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         cout << graph[i][j] <<" ";
    //     }
    //     cout << "\n";
    // }

    // for(auto &attack : attacks){
    //     cout << attack.first << attack.second << endl;
    // }
    cout << person << endl;
}