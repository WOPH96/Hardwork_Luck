#include <iostream>
#include <vector>
#include <string>

using namespace std;
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("16-3_input.txt", "r", stdin);

    string str;
    int idx;
    cin >> str >> idx;

    for (int i = 0; i < str.length(); i++)
    {
        if (i == idx)
        {
            cout << 'A';
            // continue;
        }
        cout << str[i];
    }

    return 0;
}
