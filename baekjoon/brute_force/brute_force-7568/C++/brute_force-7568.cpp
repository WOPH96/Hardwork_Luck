
// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 입력변수생성
int n;
// 다른 변수 생성
struct Person
{
    int x, y, rank;
    Person(int x, int y) : x(x), y(y) {}
    friend ostream &operator<<(ostream &out, Person &p)
    {
        out << p.x << "," << p.y;
        return out;
    }
};
struct cmp
{
    bool operator()(Person &p1, Person &p2)
    {

        return p1.x > p2.x;
    }
};

vector<Person> persons;

// 입력, 테스트 출력

void print();

void sol()
{
    // sort(persons.begin(), persons.end(), cmp());
    persons[0].rank = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (persons[i].x > persons[j].x)
            {
            }
        }
    }
}

void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        persons.emplace_back(x, y);
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 제출 시 주석처리
    freopen("brute_force-7568_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    sol();
    print();

    return 0;
}

void print()
{
    // for (auto &p : persons)
    // {
    //     cout << p << endl;
    // }
    for (auto &p : persons)
    {
        cout << p.rank << endl;
    }
}
