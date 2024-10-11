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
    int idx;
    int age;
    string name;
    Person(int i, int a, string n) : idx(i), age(a), name(n) {}
    friend ostream &operator<<(ostream &out, Person &p)
    {
        out << p.age << " " << p.name;
        return out;
    }
};

struct cmp
{
    bool operator()(Person &p1, Person &p2)
    {
        if (p1.age == p2.age)
        {
            return p1.idx < p2.idx;
        }
        return p1.age < p2.age;
    }
};
// 입력, 테스트 출력

vector<Person> persons;
void print();

void sol()
{
    sort(persons.begin(), persons.end(), cmp());
}

void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int age;
        string name;
        cin >> age >> name;
        cin.ignore();
        persons.emplace_back(i, age, name);
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 제출 시 주석처리
    freopen("sorting-10814_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();

    sol();
    print();

    return 0;
}

void print()
{
    for (auto &person : persons)
    {
        cout << person << "\n";
    }
}
