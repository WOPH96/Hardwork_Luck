// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct Grade
{
    string name;
    double value;
    string grade;
    Grade(string n, double v, string g) : name(n), value(v), grade(g) {}

    friend ostream &operator<<(ostream &out, Grade &g)
    {
        out << g.name << " " << g.value << " " << g.grade;
        return out;
    }
};
// 입력변수생성
vector<Grade> grades;
// 다른 변수 생성

// 입력, 테스트 출력
void input();
void print();

void sol()
{
    map<string, double> table = {
        {"A+", 4.5},
        {"A0", 4.0},
        {"B+", 3.5},
        {"B0", 3.0},
        {"C+", 2.5},
        {"C0", 2.0},
        {"D+", 1.5},
        {"D0", 1.0},
        {"F", 0.0},
    };
    double tot_val = 0;
    double tot_grade = 0;
    for (auto &grade : grades)
    {
        if (grade.grade != "P")
        {
            tot_val += grade.value;
            tot_grade += grade.value * table[grade.grade];
        }
    }
    cout << tot_grade / tot_val << endl;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 제출 시 주석처리
    // freopen("string-25206_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    // print();
    sol();

    return 0;
}

void input()
{
    for (int i = 0; i < 20; i++)
    {
        string name;
        double value;
        string grade;
        cin >> name >> value >> grade;
        grades.push_back(Grade(name, value, grade));
    }
}
void print()
{
    for (auto &str : grades)
    {
        cout << str << endl;
    }
}
