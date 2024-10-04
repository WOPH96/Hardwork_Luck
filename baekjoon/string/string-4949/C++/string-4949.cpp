// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// 입력변수생성
vector<string> strs;
// 다른 변수 생성

// 입력, 테스트 출력
void input();
void print();

void sol()
{
    for (auto &str : strs)
    {
        stack<char> st;
        bool break_flag = false;
        for (char &ch : str)
        {
            if (ch == '(' || ch == '[')
            {
                st.push(ch);
            }
            else if (ch == ')' || ch == ']')
            {
                if (st.empty())
                {
                    break_flag = true;
                    break;
                }
                else
                {
                    char top = st.top();
                    st.pop();
                    if ((top == '(' && ch == ']') ||
                        (top == '[' && ch == ')'))
                    {
                        break_flag = true;
                        break;
                    }
                }
            }
        }
        if (break_flag || !st.empty())
        {
            cout << "no" << endl;
        }
        else
        {
            cout << "yes" << endl;
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 제출 시 주석처리
    // freopen("string-4949_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    // print();
    sol();

    return 0;
}

void input()
{
    string str;
    while (1)
    {
        getline(cin, str);
        if (str[0] == '.' && str.length() == 1)
            break;
        strs.push_back(str);
    }
}
void print()
{
    for (auto &str : strs)
    {
        cout << str << endl;
    }
}
