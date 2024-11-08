// #include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

// 입력변수생성
int t;
// 다른 변수 생성

// 입력, 테스트 출력
struct Pos
{
    int y, x;
    Pos() : y(0), x(0) {}
    Pos(int y, int x) : y(y), x(x) {}
    friend ostream &operator<<(ostream &out, Pos &p)
    {
        out << "(" << p.y << "," << p.x << ")";
        return out;
    }
};
void print(int n, Pos &house, Pos *conv, Pos &dest);

void sol(Pos &house, Pos *conv, Pos &dest)
{
}

void input()
{
    cin >> t;
    while (t)
    {
        int n;
        Pos house;
        Pos *Conv = new Pos[n];
        Pos dest;
        cin >> n;
        cin >> house.y >> house.x;

        for (int i = 0; i < n; i++)
        {
            cin >> Conv[i].y >> Conv[i].x;
        }
        cin >> dest.y >> dest.x;
        sol(house, Conv, dest);
        print(n, house, Conv, dest);
        delete[] Conv;
        t--;
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 제출 시 주석처리
    freopen("graph_search-9205_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    // sol();
    // print();

    return 0;
}

void print(int n, Pos &house, Pos *conv, Pos &dest)
{
    cout << house << endl;
    for (int i = 0; i < n; i++)
    {
        cout << conv[i] << endl;
    }
    cout << dest << endl;
    cout << endl;
}
