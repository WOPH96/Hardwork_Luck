// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

// 입력변수생성
int n;
// 다른 변수 생성
int sum = 0;
struct Freq
{
    int num, cnt;
    Freq(int n, int c) : num(n), cnt(c)
    {
    }
    bool operator<(const Freq &f) const
    {
        if (this->cnt == f.cnt)
        {
            return this->num < f.num;
        }
        return this->cnt > f.cnt;
    }
    friend ostream &operator<<(ostream &out, Freq &f)
    {
        out << f.num << ":" << f.cnt;
        return out;
    }
};
vector<int> datas;
map<int, int> temp_maps;
vector<Freq> freq_datas;
// 입력, 테스트 출력

void print();

int get_freq()
{
    for (auto &elem : temp_maps)
    {
        freq_datas.emplace_back(elem.first, elem.second);
        // cout << elem.first << ":" << elem.second << endl;
    }
    sort(freq_datas.begin(), freq_datas.end());
    if (freq_datas[0].cnt == freq_datas[1].cnt)
    {
        return freq_datas[1].num;
    }
    else
    {
        return freq_datas[0].num;
    }
}
int get_middle()
{
    sort(datas.begin(), datas.end());
    return datas[(n - 1) / 2];
}
struct Result
{
    double arith_mean;
    int middle_data;
    int freq_data;
    int range;
    friend ostream &operator<<(ostream &out, Result &r)
    {
        // out << fixed;
        if (r.arith_mean == 0)
            r.arith_mean = abs(r.arith_mean);
        out << r.arith_mean << "\n"
            << r.middle_data << "\n"
            << r.freq_data << "\n"
            << r.range << "\n";
        return out;
    }
};
void sol()
{

    Result result;
    result.arith_mean = round((double)(sum / (double)n));
    result.middle_data = get_middle();
    result.freq_data = get_freq();
    result.range = datas[n - 1] - datas[0];
    // cout << fixed;
    // cout.precision(0);
    cout << result;
}

void input()
{
    cin >> n;
    // freq_datas.resize(n, Freq(0, 0));
    for (int i = 0; i < n; i++)
    {
        int data;
        cin >> data;
        sum += data;
        datas.push_back(data);
        temp_maps[data]++;
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 제출 시 주석처리
    // freopen("sorting-2108_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    sol();
    // print();

    return 0;
}

void print()
{
    for (auto &freq_data : freq_datas)
    {
        cout << freq_data << " ";
    }
    cout << endl;
}
