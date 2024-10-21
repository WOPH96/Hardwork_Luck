// #include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

// 입력변수생성
int first, last;
// 다른 변수 생성
vector<int> sequence;
// 입력, 테스트 출력

void print();

void sol()
{
    for (int i = 1; i <= last; i++)
    {
        for (int j = 0; j < i; j++)
        {
            sequence.push_back(i);
        }
    }
    int sum = 0;
    for (int i = first - 1; i < last; i++)
    {
        sum += sequence[i];
    }
    // for (auto &seq : sequence)
    // {
    //     cout << seq << " ";
    // }
    cout << sum << endl;
}

void input()
{
    cin >> first >> last;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 제출 시 주석처리
    // freopen("recommand-1292_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    sol();
    print();

    return 0;
}

void print()
{
}
