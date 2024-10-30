// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 입력변수생성
int n;
// 다른 변수 생성
struct Num{
int idx, data, order;
Num(int i, int d, int o) : idx(i), data(d), order(o){}
};
vector<Num> nums;
// 입력, 테스트 출력

void print();

void sol(){
    sort(nums.begin(), nums.end(),[](Num & n1, Num& n2){
        return n1.data < n2.data;
    });
    int prev = nums[0].data;
    nums[0].order = 0;
    
    for(int i=0;i<n;i++){
        if(nums[i].data == prev){
            nums[i].order = nums[i-1].order;
        }
        else{
            nums[i].order = nums[i-1].order + 1;
            prev = nums[i].data;
        }
    }

    sort(nums.begin(), nums.end(),[](Num & n1, Num& n2){
        return n1.idx < n2.idx;
    });

}

void input() {
    cin >> n;
    for(int i=0;i<n;i++){
        int data;
        cin >> data;
        nums.emplace_back(i, data, 0);
    }
    
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 제출 시 주석처리
    // freopen("sorting-18870_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    sol();
    print();

    return 0;
}


void print() {
    for(auto &elem : nums){
        cout <<  elem.order<< " ";
    }
    cout << endl;
} 
