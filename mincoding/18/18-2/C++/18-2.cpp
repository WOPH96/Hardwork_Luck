#include <iostream>
#include <vector>

using namespace std;

int datas[9];
void check();

int main()
{
    // std::ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // freopen("18-2_input.txt", "r", stdin);
    int nums[10] = {0};
    for (int i = 0; i < 9; i++)
    {
        cin >> datas[i];
        nums[datas[i]] += 1;
    }

    // check();

    for (int i = 1; i < 10; i++)
    {
        if (nums[i] == 0)
        {
            cout << i << " ";
        }
    }
    return 0;
}

void check()
{
    for (int i = 0; i < 9; i++)
    {
        cout << datas[i] << " ";
    }
}