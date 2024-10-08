// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <queue>

using namespace std;

// 입력변수생성
int n;
// 다른 변수 생성
struct Command
{
    string command;
    int val;
    Command(string c, int v = 0) : command(c), val(v) {}
    friend ostream &operator<<(ostream &out, Command &c)
    {

        out << c.command << " " << c.val;
        return out;
    }
};

vector<Command> coms;
// 입력, 테스트 출력

void print();

void sol()
{
    queue<int> q;
    for (auto &com : coms)
    {
        if (com.command.compare("push") == 0)
        {
            q.push(com.val);
            // cout << com.val << endl;
        }
        else if (com.command.compare("pop") == 0)
        {
            if (q.empty())
                cout << -1 << endl;
            else
            {
                int top = q.front();
                cout << top << endl;
                q.pop();
            }
        }
        else if (com.command.compare("size") == 0)
        {
            cout << q.size() << endl;
        }
        else if (com.command.compare("empty") == 0)
        {
            cout << q.empty() << endl;
        }
        else if (com.command.compare("front") == 0)
        {
            if (q.empty())
            {
                cout << -1 << endl;
            }
            else
            {
                cout << q.front() << endl;
            }
        }
        else if (com.command.compare("back") == 0)
        {
            if (q.empty())
            {
                cout << -1 << endl;
            }
            else
            {
                cout << q.back() << endl;
            }
        }
    }
}

void input()
{
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        string str;
        int val = 0;
        cin >> str;
        if (str.compare("push") == 0)
        {
            cin >> val;
            cin.ignore();
        }
        coms.emplace_back(str, val);
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 제출 시 주석처리
    // freopen("queue-10845_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    // print();
    sol();

    return 0;
}

void print()
{
    for (auto &com : coms)
    {
        cout << com << endl;
    }
}
