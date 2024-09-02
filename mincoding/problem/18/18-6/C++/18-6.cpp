#include <iostream>
#include <vector>

using namespace std;
int main()
{
    // std::ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // freopen("18-6_input.txt", "r", stdin);

    string suspect;
    cin >> suspect;

    char town[3][3] = {
        {'C', 'D', 'A'},
        {'B', 'M', 'Z'},
        {'Q', 'P', 'O'}};

    char black_list[100] = {0};
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            black_list[town[i][j]] = 1;
        }
    }
    int blacked_person = 0;
    for (char &elem : suspect)
    {
        if (black_list[elem] == 1)
            blacked_person++;
    }

    cout << blacked_person << "명";
    return 0;
}
