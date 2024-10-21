// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
#define FAIL           \
    wrong_flag = true; \
    break;
// 입력변수생성
string str;

// 다른 변수 생성

// 입력, 테스트 출력

void print();

bool check_brace()
{
    stack<char> st;
    bool wrong_flag = false;
    for (auto brace : str)
    {
        if (brace == '(' || brace == '[')
        {
            st.push(brace);
        }
        else
        {
            if (st.empty())
            {
                FAIL
            }
            if (brace == ')')
            {
                if (st.top() == '(')
                {
                    st.pop();
                }
                else
                {
                    FAIL
                }
            }
            // ]
            else
            {
                if (st.top() == '[')
                {
                    st.pop();
                }
                else
                {
                    FAIL
                }
            }
        }
    }
    if (st.empty() && !wrong_flag)
    {
        return true;
    }
    else
        return false;
}

void sol()
{
    if (!check_brace())
    {
        cout << 0 << endl;
        return;
    }

    // 정상 괄호인 경우
    auto it_small = str.find("()");
    while (it_small != string::npos)
    {
        str.replace(it_small, 2, "2");
        it_small = str.find("()");
    }

    auto it_middle = str.find("[]");
    while (it_middle != string::npos)
    {
        str.replace(it_middle, 2, "3");
        it_middle = str.find("[]");
    }
    cout << str << endl;
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
    freopen("recommand-2504_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    sol();
    print();

    return 0;
}

void print()
{
}
