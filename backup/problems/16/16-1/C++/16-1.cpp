#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{

    vector<string> strs;
    string sentence;
    for (int i = 0; i < 3; i++)
    {
        cin >> sentence;
        strs.push_back(sentence);
    }
    for (string elem : strs)
    {
        cout << elem.back();
    }

    return 0;
}