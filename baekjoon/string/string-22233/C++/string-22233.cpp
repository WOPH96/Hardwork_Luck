// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

// 입력변수생성
int n, m;
// 다른 변수 생성
unordered_map<string, int> keywords;
// vector<string> blog_words[200001];
// 입력, 테스트 출력

void print();

// void sol()
// {
//     int cnt = n;
//     for (int i = 0; i < m; i++)
//     {

//         for (auto &blog_word : blog_words[i])
//         {
//             if (keywords[blog_word] == 1)
//             {
//                 keywords[blog_word]--;
//                 cnt--;
//             }
//         }
//         // for (auto &elem : keywords)
//         // {
//         //     // cout << elem.first << ":" << elem.second << " ";
//         //     if (elem.second == 1)
//         //     {
//         //         cnt++;
//         //     }
//         // }
//         cout << cnt << "\n";
//     }
// }
void split_push_back(string &str)
{
    string word;
    istringstream iss(str);
    while (getline(iss, word, ','))
    {

        // words.push_back(word);

        if (keywords[word] == 1)
        {
            keywords[word]--;
            n--;
        }
    }
    cout << n << "\n";
}
void input()
{
    // cin.tie(nullptr);
    cin >> n >> m;
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        string str;
        getline(cin, str);
        keywords[str]++;
    }
    for (int i = 0; i < m; i++)
    {
        string str;
        getline(cin, str);
        split_push_back(str);
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 제출 시 주석처리
    // freopen("string-22233_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    // print();
    // sol();

    return 0;
}

// void print()
// {
//     for (int i = 0; i < m; i++)
//     {
//         for (auto &word : blog_words[i])
//         {
//             cout << word << " ";
//         }
//         cout << "\n";
//     }
// }
