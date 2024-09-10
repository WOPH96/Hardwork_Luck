// #include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

// 입력변수생성
int n;
class Person
{
public:
    int weight;
    int height;
};
// 입력변수생성

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("brute_force-7568_input.txt", "r", stdin);
    cin >> n;
    Person *p = new Person[n]();
    for (int i = 0; i < n; i++)
    {

        cin >> p[i].weight >> p[i].height;
    }

    for (int i = 0; i < n; i++)
    {
        cout << p[i].weight << " " << p[i].height << endl;
    }
    delete[] p;
    return 0;
}
