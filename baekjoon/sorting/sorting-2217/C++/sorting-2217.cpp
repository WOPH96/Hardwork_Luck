// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 입력변수생성
int n;
// 다른 변수 생성
vector<int> lopes;
// 입력, 테스트 출력

void print();

void sol(){
    sort(lopes.begin(), lopes.end());
    int max_weight = lopes[0]*n;
    cout << max_weight << "\n";
}

void input() {
    cin >> n;
    for(int i=0;i<n;i++){
        int lope;
        cin >> lope;
        lopes.push_back(lope);

    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 제출 시 주석처리
    // freopen("sorting-2217_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    sol();
    print();

    return 0;
}


void print() {

} 
