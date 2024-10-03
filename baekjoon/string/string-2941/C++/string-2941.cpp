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

void sol()
{
    vector<char> check_list = {'c', 'd', 'z', 'l', 'n', 's'};
    stack<char> st;
    int cnt = 0;
    for (char &ch : str)
    {
        auto it = find(check_list.begin(), check_list.end(), ch);
        // 찾았다면
        if (it != check_list.end())
        {
            if (!st.empty() && st.top() == 'd' && ch == 'z')
                st.pop();
            st.push(ch);
        }
        else
        {
            if (ch == '=')
            {
                if (st.top() =)
            }
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 제출 시 주석처리
    freopen("string-2941_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    print();
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
