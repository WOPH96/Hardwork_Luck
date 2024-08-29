#include <iostream>
#include <vector>

using namespace std;
int arr[2][4];
void print();
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("16-4_input.txt", "r", stdin);

    int num;

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> num;
            arr[i][j] = num;
        }
    }

    int result[4];
    for (int j = 0; j < 4; j++)
    {
        result[j] = arr[0][j] + arr[1][3 - j];
    }
    for (int j = 0; j < 4; j++)
    {
        cout << result[j] << " ";
    }
    return 0;
}

void print()
{
    for (auto &arrs : arr)
    {
        for (auto &elem : arrs)
        {
            cout << elem;
        }
    }
}