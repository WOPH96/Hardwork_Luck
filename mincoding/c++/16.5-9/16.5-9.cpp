#include <iostream>
#include <vector>

using namespace std;
int main()
{
    // std::ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // freopen("16.5-9_input.txt", "r", stdin);

    int num1, num2;
    char ch;

    cin >> num1 >> num2 >> ch;

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < num1; j++)
        {
            for (int k = 0; k < num2; k++)
            {
                cout << ch;
            }
            cout << "\n";
        }
        cout << "\n";
    }

    return 0;
}
