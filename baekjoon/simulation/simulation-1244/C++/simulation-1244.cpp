// #include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

// 입력변수생성
int n;
bool switchs[101] = {0};
int num_st;
// 다른 변수 생성
struct Student
{
    int gender;
    int number;
    Student(int g, int n) : gender(g), number(n) {}
    void switch_toggle_man();
    void switch_toggle_woman();
};
vector<Student> students;

enum State
{
    OFF = 0,
    ON
};

enum Gender
{
    MAN = 1,
    WOMAN
};

// 입력, 테스트 출력

void print();

void Student::switch_toggle_man()
{
    for (int i = this->number; i <= n; i += this->number)
    {
        switchs[i] ^= 1;
        // ON -> OFF
        // OFF -> ON
    }
    // print();
    // cout << "===" << endl;
}

bool is_valid(int a, int b)
{
    return (a - b >= 1 && a + b <= n);
}

void Student::switch_toggle_woman()
{
    int idx = 1;
    switchs[this->number] ^= 1;
    // 대칭인 동안만 수행
    while (is_valid(this->number, idx) && switchs[this->number - idx] == switchs[this->number + idx])
    {
        switchs[this->number - idx] ^= 1;
        switchs[this->number + idx] ^= 1;
        // ON -> OFF
        // OFF -> ON
        idx++;
        // print();
    }
}

void sol()
{
    for (auto &student : students)
    {
        if (student.gender == MAN)
        {
            student.switch_toggle_man();
        }
        else
        {
            student.switch_toggle_woman();
        }
    }
}

void input()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> switchs[i];
    }
    cin >> num_st;
    for (int i = 0; i < num_st; i++)
    {
        int g, n;
        cin >> g >> n;
        students.emplace_back(g, n);
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 제출 시 주석처리
    freopen("simulation-1244_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    // print();
    sol();
    print();

    return 0;
}

void print()
{
    bool stop_flag = false;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 1; j <= 20; j++)
        {
            if (!is_valid(j + 20 * i, 0))
            {
                stop_flag = true;
                break;
            }
            cout << switchs[j + 20 * i] << " ";
        }
        cout << endl;
        if (stop_flag)
            break;
    }
    // cout << endl;
}
