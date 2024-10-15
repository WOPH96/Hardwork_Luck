// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

// 입력변수생성
string plain_txt, key;
vector<string> text_pair;
vector<string> authorized_text;

struct Pos
{
    int y, x;
    Pos() : y(0), x(0) {}
    Pos(int y, int x) : y(y), x(x) {}
};
// 다른 변수 생성
char key_box[5][5] = {0};
unordered_map<char, Pos> dict;
// 입력, 테스트 출력

void print();

Pos one2two(int val)
{
    int y, x;
    // val = 1 ->[0][1]
    // val = 7 ->[1][2]
    y = val / 5;
    x = val % 5;
    return Pos(y, x);
}
void make_keybox()
{
    int alpha[25] = {0};
    // key 먼저 삽입
    char *key_box_ptr = &key_box[0][0];
    int cnt = 0;
    int j_idx = 'J' - 'A';

    for (char &ch : key)
    {
        int idx = ch - 'A';
        if (idx > j_idx)
        {
            idx--;
        }
        if (alpha[idx] == 0)
        {
            // cout << ch << endl;
            *(key_box_ptr + cnt) = ch;
            dict[ch] = one2two(cnt);
            alpha[idx] = 1;
            cnt++;
        }
    }
    for (int i = 0; i < 25; i++)
    {

        if (alpha[i] == 0)
        {
            char ch;
            if (i >= j_idx)
                ch = (i + 'A' + 1);
            else
                ch = (i + 'A');
            *(key_box_ptr + cnt) = ch;
            dict[ch] = one2two(cnt);
            alpha[i] = 1;
            cnt++;
        }
    }
}
// void split_plain_text()
// {
//     // plain_txt.insert(3, 1, 'a');
//     int itr = 0;
//     // cout << plain_txt.substr(itr, 2) << endl;
//     // int debug_cnt = 0;
//     while (1)
//     {
//         // debug_cnt++;
//         int size = plain_txt.size();
//         if (itr > size - 1)
//             break;
//         string temp = plain_txt.substr(itr, 2);
//         if (temp[0] != temp[1])
//         {
//             text_pair.push_back(temp);
//             itr += 2;
//         }
//         if (itr == size - 1)
//         {
//             plain_txt.insert(itr + 1, 1, 'X');
//         }
//         else if (temp[0] == temp[1])
//         {
//             if (temp[0] == 'X')
//             {
//                 plain_txt.insert(itr + 1, 1, 'Q');
//             }
//             else
//                 plain_txt.insert(itr + 1, 1, 'X');
//         }
//         // cout << plain_txt << endl;
//         // if (debug_cnt > 20)
//         //     break;
//     }
// }
void split_plain_text()
{
    for (size_t i = 0; i < plain_txt.length(); i += 2)
    {
        if (i + 1 == plain_txt.length())
        {
            text_pair.push_back(plain_txt.substr(i, 1) + "X");
        }
        else if (plain_txt[i] == plain_txt[i + 1])
        {
            text_pair.push_back(string(1, plain_txt[i]) + (plain_txt[i] == 'X' ? "Q" : "X"));
            i--;
        }
        else
        {
            text_pair.push_back(plain_txt.substr(i, 2));
        }
    }
}
void do_authorize()
{
    for (auto &text : text_pair)
    {
        string tmp;
        if (dict[text[0]].y == dict[text[1]].y)
        {
            int x1, x2;
            x1 = (dict[text[0]].x + 1) % 5;
            x2 = (dict[text[1]].x + 1) % 5;
            // tmp = key_box[dict[text[0]].y][x1] + key_box[dict[text[1]].y][x2];
            tmp.push_back(key_box[dict[text[0]].y][x1]);
            tmp.push_back(key_box[dict[text[1]].y][x2]);
        }
        else if (dict[text[0]].x == dict[text[1]].x)
        {
            int y1, y2;
            y1 = (dict[text[0]].y + 1) % 5;
            y2 = (dict[text[1]].y + 1) % 5;
            tmp.push_back(key_box[y1][dict[text[0]].x]);
            tmp.push_back(key_box[y2][dict[text[1]].x]);
        }
        else
        {
            tmp.push_back(key_box[dict[text[0]].y][dict[text[1]].x]);
            tmp.push_back(key_box[dict[text[1]].y][dict[text[0]].x]);
        }
        // cout << text << " " << tmp << endl;
        authorized_text.push_back(tmp);
    }
}
void sol()
{
    make_keybox();
    split_plain_text();
    do_authorize();

    for (auto &elem : authorized_text)
    {
        cout << elem;
    }
    cout << endl;
}

void input()
{
    cin >> plain_txt;
    cin >> key;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 제출 시 주석처리
    // freopen("playfair_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    sol();
    // print();

    return 0;
}

void print()
{
    cout << plain_txt << endl;
    cout << key << endl;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << key_box[i][j] << " ";
        }
        cout << endl;
    }

    for (auto &elem : text_pair)
    {
        cout << elem << endl;
    }

    for (auto &elem : dict)
    {
        cout << elem.first << ":" << elem.second.y << "," << elem.second.x << endl;
    }
}
