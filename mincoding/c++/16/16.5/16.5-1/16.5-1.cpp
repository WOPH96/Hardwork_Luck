#include <iostream>
#include <vector>

using namespace std;
int main()
{
    // std::ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // freopen("16.5-1_input.txt", "r", stdin);

    int a, b, c;
    for (int i = 0; i < 3; i++)
    {
        cin >> a >> b >> c;
    }

    for (int i = 0; i < c; i++)
    {
        for (int j = a; j <= b; j++)
        {
            cout << j << " ";
        }
        cout << "\n";
    }

    return 0;
}
