#include <iostream>
#include <vector>
#include <map>

using namespace std;

int MAP[3][4] = {
    {65000, 35, 42, 70},
    {70, 35, 65000, 1300},
    {65000, 30000, 38, 42}};

int main()
{
    // std::ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // freopen("18-1_input.txt", "r", stdin);
    map<int, int> hardwork;
    // cout << ++hardwork[35] << endl;
    // -- > 없는 키 값 참조 시 에러안남 확인
    for (auto &arr : MAP)
    {
        for (int &elem : arr)
        {
            hardwork[elem] += 1;
        }
    }

    for (auto &elem : hardwork)
    {
        cout << elem.first << " " << elem.second << "\n";
    }

    return 0;
}
