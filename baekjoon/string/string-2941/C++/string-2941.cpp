// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

// 입력변수생성
string str;
// 다른 변수 생성
/*
č	c=
ć	c-
dž	dz=
đ	d-
lj	lj
nj	nj
š	s=
ž	z=
c,d,z,l,n,s 가 나오면
한번 더 기다린다
*/
// 입력, 테스트 출력
void input();
void print();

// void sol()
// {
//     vector<char> check_list = {'c', 'd', 'z', 'l', 'n', 's'};
//     stack<char> st;
//     int cnt = 0;
//     for (char &ch : str)
//     {
//         auto it = find(check_list.begin(), check_list.end(), ch);
//         // 찾았다면
//         if (it != check_list.end())
//         {
//             if (!st.empty() && st.top() == 'd' && ch == 'z')
//                 st.pop();
//             st.push(ch);
//         }
//         else
//         {
//             if (ch == '=')
//             {
//                 vector<char> equal_list{'c', 'z', 's'};
//                 auto it = find(equal_list.begin(), equal_list.end(), st.top());
//                 if (it != equal_list.end())
//                 {
//                     st.pop();
//                     cnt++;
//                 }
//             }
//             else if (ch == '-')
//             {
//                 vector<char> minus_list{'c', 'd'};
//                 auto it = find(minus_list.begin(), minus_list.end(), st.top());
//                 if (it != minus_list.end())
//                 {
//                     st.pop();
//                     cnt++;
//                 }
//             }
//             else if (ch == 'j')
//             {
//                 vector<char> minus_list{'l', 'n'};
//                 auto it = find(minus_list.begin(), minus_list.end(), st.top());
//                 st.pop();
//                 if (it != minus_list.end())
//                 {
//                     cnt++;
//                 }
//                 else
//                 {
//                     cnt += 2;
//                 }
//             }
//             else
//             {
//                 if (!st.empty())
//                     st.pop();
//                 cnt++;
//             }
//         }
//     }
//     cout << cnt << endl;
// }

void sol()
{
    vector<string> check_list = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};
    int cnt = 0;
    for (auto st : check_list)
    {
        auto it = str.find(st);
        int len = st.length();
        // auto it = find(str.begin(), str.end(), st);
        // 해당 단어를 못찾을 때까지
        while (it != string::npos)
        {
            // cout << st << ": ";
            // cout << str << endl;
            str = str.substr(0, it) + "," + str.substr(it + len);
            cnt++;
            // cout << str << endl;
            // cout << cnt << endl;
            it = str.find(st);
        }
        // cout << str << endl;
        // break;
    }
    int comma_cnt = 0;
    for (auto &ch : str)
    {
        if (ch == ',')
        {
            comma_cnt++;
        }
    }
    cout << cnt + str.length() - comma_cnt << endl;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 제출 시 주석처리
    // freopen("string-2941_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    // print();
    sol();

    return 0;
}

void input()
{
    cin >> str;
}
void print()
{
    cout << str;
}
