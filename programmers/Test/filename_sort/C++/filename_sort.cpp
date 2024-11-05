#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
struct File
{
    string head, numbers, tails;

    File(string h, string n, string t) : head(h), numbers(n), tails(t) {}
    friend ostream &operator<<(ostream &out, File &f)
    {
        out << f.head << f.numbers << f.tails;
        return out;
    }
};

struct cmp
{
    bool operator()(const File &f1, const File &f2)
    {
        // NUMBER 비교
        string temp1 = f1.head;
        string temp2 = f2.head;
        transform(f1.head.begin(), f1.head.end(), temp1.begin(), ::toupper);
        transform(f2.head.begin(), f2.head.end(), temp2.begin(), ::toupper);
        // cout << temp1 << temp2 << endl;
        if (temp1 == temp2)
        {

            return stoi(f1.numbers) < stoi(f2.numbers);
        }

        else
        {

            return temp1 < temp2;
        }
    }
};

bool is_number(const char &ch)
{
    return (ch - '0' >= 0 && ch - '0' <= 9);
}
vector<string> solution(vector<string> files)
{
    vector<string> answer;
    vector<File> fs;
    for (auto &f : files)
    {
        string head = "";
        string number = "";
        string tail = "";
        int i = 0;
        for (; i < f.size(); i++)
        {
            if (is_number(f[i]))
                break;
            head += f[i];
        }

        // cout << head << endl;
        for (; i < f.size(); i++)
        {
            if (!is_number(f[i]))
                break;
            number += f[i];
        }

        for (; i < f.size(); i++)
        {

            tail += f[i];
        }
        // cout << tail << endl;
        fs.emplace_back(head, number, tail);
    }
    stable_sort(fs.begin(), fs.end(), cmp());
    for (auto &elem : fs)
    {
        answer.push_back(elem.head + elem.numbers + elem.tails);
    }

    return answer;
}