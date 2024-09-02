#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 입력변수생성
string words;
// 입력변수생성
int main()
{
    // std::ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // freopen("18.5-11_input.txt", "r", stdin);
    cin >> words;

    auto pos = words.find("GHOST");
    if (pos != string::npos)
    {
        cout << "존재";
    }
    else
    {
        cout << "존재하지 않음";
    }
    return 0;
}
