#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int N, K;
vector<pair<int, int>> recipes;
vector<int> materials;
int max_bottle = -1;
void backtrack(int depth, int data)
{
    if (depth == N)
    {
        int cnt = 0;
        for (auto &elem : recipes)
        {
            auto it_1 = find(materials.begin(), materials.end(), elem.first);
            auto it_2 = find(materials.begin(), materials.end(), elem.second);
            if (it_1 != materials.end() &&
                it_2 != materials.end())
                cnt++;
        }
        max_bottle = max(cnt, max_bottle);
        return;
    }
}

int main()
{
    cin >> N >> K;
    for (int i = 0; i < K; i++)
    {
        int A, B;
        cin >> A >> B;
        recipes.push_back({A, B});
    }

    // Please write your code here.

    return 0;
}
