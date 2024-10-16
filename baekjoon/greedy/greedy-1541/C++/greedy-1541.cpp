// #include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

// 입력변수생성
string str;
// 다른 변수 생성

// 입력, 테스트 출력

void print();
bool is_num(char &ch)
{
    return (0 <= ch - '0' && ch - '0' <= 9);
}
void sol()
{
    string num;
    long long res = 0;
    int num_cnt = 0;
    int flag = 1;
    for (char &elem : str)
    {

        if (is_num(elem))
        {
            // cout << elem << endl;
            num += elem;
        }
        // + or - 인 경우
        else
        {

            if (num_cnt == 0)
            {
                res = stoi(num);
            }
            else
            {
                // cout << flag << endl;

                res += stoi(num) * flag;
            }
            if (elem == '-')
            {
                flag = -1;
                // cout << "hello";
            }
            // cout << res << endl;
            // cout << stoi(num) << endl;

            num.clear();
            num_cnt++;
        }
    }
    res += stoi(num) * flag;
    cout << res << endl;
}

void input()
{
    cin >> str;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 제출 시 주석처리
    // freopen("greedy-1541_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    sol();
    // print();

    return 0;
}

void print()
{
    cout << str << endl;
}
