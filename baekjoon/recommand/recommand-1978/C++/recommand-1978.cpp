// #include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

// 입력변수생성
int n;
vector<int> nums;
// 다른 변수 생성

// 입력, 테스트 출력

void print();

bool is_primary(int num)
{
    int cnt = 0;
    for (int i = 1; i <= num; i++)
    {
        if (num % i == 0)
            cnt++;
    }
    if (cnt == 2)
        return true;
    else
        return false;
}

void sol()
{
    int cnt = 0;
    for (int &num : nums)
    {
        if (is_primary(num))
            cnt++;
    }
    cout << cnt << endl;
}

void input()
{
    cin >> n;
    while (n)
    {
        int num;
        cin >> num;
        nums.push_back(num);

        n--;
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 제출 시 주석처리
    // freopen("recommand-1978_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    sol();
    print();

    return 0;
}

void print()
{
}
