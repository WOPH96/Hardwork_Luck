#include <iostream>
#include <vector>

using namespace std;

char target;
string arr = "MTKC";

bool isExist();
int main()
{
    // std::ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // freopen("17-1_input.txt", "r", stdin);

    cin >> target;

    // cout << arr.size();
    if (isExist())
        cout << "발견";
    else
        cout << "미발견";

    return 0;
}

bool isExist()
{
    for (char &elem : arr)
    {
        if (elem == target)
            return true;
    }
    return false;
}