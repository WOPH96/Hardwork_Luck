#include <iostream>
#include <cmath>

using namespace std;

typedef unsigned long long ull;

ull S;

void sol()
{
    // n * (n + 1) / 2 <= S
    // n^2 + n - 2S <= 0
    // 근의 공식 ->
    // -b +- root(b^2 -4ac) /
    // 2a
    // -> (-1 + sqrt(1+8.0*S))/2
    ull result = static_cast<ull>((-1 + sqrt(1 + 8.0 * S)) / 2);
    cout << result << endl;
}

void input()
{
    cin >> S;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 제출 시 주석처리
    freopen("greedy-1781_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    sol();
    // print();

    return 0;
}

void print()
{
}
