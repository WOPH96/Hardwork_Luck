#include <iostream>
#include <vector>
#include <string>
using namespace std;

string exist_words = "GKG";
int main()
{
    // std::ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // freopen("18.5-1_input.txt", "r", stdin);

    for (int i = 0; i < 3; i++)
    {
        char word;
        cin >> word;
        exist_words.push_back(word);
    }

    int lists[100] = {0};

    for (char &elem : exist_words)
    {
        lists[elem]++;
        if (lists[elem] >= 3)
        {
            cout << "있음";
            return 0;
        }
    }
    cout << "없음";
    return 0;
}
