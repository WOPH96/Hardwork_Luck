// #include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

// 입력변수생성
int coms;
int n;

vector<int> graph[101]; // 벡터를 요소로 갖는 101개의 배열, 그래프로 사용
// 입력변수생성

// 입력, 테스트 출력
void input();
void print();

// void sol(){
// }

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 제출 시 주석처리
    freopen("graph_search-2606_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    print();
    // sol();

    return 0;
}

void input()
{
    cin >> coms >> n;

    for (int i = 0; i < n; i++)
    {
        int idx, neighbor;
        cin >> idx >> neighbor;
        graph[idx].push_back(neighbor);
        graph[neighbor].push_back(idx);
    }
}
void print()
{
    for (int i = 0; i < n; i++)
    {
        cout << i << "  ";
        for (auto &elem : graph[i])
        {
            cout << elem << " ";
        }
        cout << endl;
    }
}